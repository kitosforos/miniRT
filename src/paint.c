/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:12:24 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/07/07 18:13:11 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <unistd.h>
#include "paint.h"
#include "rt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_color	ray_color(t_ray ray, t_hittables *h)
{
	double			t;
	t_hit_record	rec;
	t_coord			unt;
	
	if (hit(h, ray, 0, DBL_MAX, &rec)) {
		unt = unit_vector(rec.normal);
		return (new_color((0.5 * (unt.x + 1)) * 255, (0.5 * (unt.y + 1)) * 255, (0.5 * (unt.z + 1)) * 255));;
	}
	unt = unit_vector(ray.direction);
	t = 0.5*(unt.y+1.0);

	return (new_color((1.0-t)*255 + t*0.5*255, (1.0-t)*255 + t*0.7*255, (1.0-t)*255 + t*255));
}	

int	hit(t_hittables *t, t_ray r, double t_min, double t_max, t_hit_record *rec)
{
	int				i;
    t_hit_record	temp_rec;
    int 			hit_anything = 0;
    double 			closest_so_far = t_max;

	i = 0;

    while (i < t->n_spheres)
	{
		if (sphere_hit(r, t_min, closest_so_far, &temp_rec, *(t->spheres[i])) > 0)
		{
			hit_anything = 1;
			closest_so_far = temp_rec.t;
			*rec = temp_rec;
		}
		i++;
    }
    return hit_anything;
}

void write_color(t_data *data, t_color col, int i, int j, int samples_per_pixel)
{
    int r = col.r;
    int g = col.g;
    int b = col.b;

    // Divide the color by the number of samples.
    double scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

	my_mlx_pixel_put(data, i, j, (r << 16) | (g << 8) | (	b));
	
}

int	paint_objects(t_data *data, t_program *program) 
{
	int		i;
	int		j;
	double	u;
	double	v;
	t_ray	ray;
	t_color	pixel_col;
	t_color	col;
	program = program;
	t_hittables world;
	world.n_spheres = 0;
	t_sphere sp, sp2;
	sp.diametre = 1;
	sp.coord = new_coord(0, 0, -1);
	sp.color = new_color(255, 0, 0);
	sp2.diametre = 200;
	sp2.coord = new_coord(0, -100.5, -1);
	sp2.color = new_color(0, 255, 0);
	int samples_per_pixel = 10;
	srand(time(NULL));
	//World
	add_sphere(&world, &sp);
	add_sphere(&world, &sp2);
	//Camera
	double viewport_height = 2, viewport_width = viewport_height * (16.0/9.0);
	t_coord horizontal = new_coord(viewport_width, 0, 0);
	t_coord vertical = new_coord(0, viewport_height, 0);
	t_coord lower_left_corner = resta_vect(resta_vect(new_coord(0,0,0), div_vect(horizontal, 2)), resta_vect(div_vect(vertical, 2), new_coord(0,0,1)));
	for (j = RES_HEIGHT - 1; j >= 0; j--)
	{
		for (i = 0; i < RES_WIDTH; ++i)
		{
			pixel_col = new_color(0, 0, 0);
			for (int s = 0; s < samples_per_pixel; ++s)
			{
				u = ((double)i + randomize()) / (RES_WIDTH - 1);
				v = ((double)j + randomize()) / (RES_HEIGHT - 1);
				ray.origin = new_coord(0,0,0);
				ray.direction = suma_vect(suma_vect(lower_left_corner, prod_vect(horizontal, u)), resta_vect(prod_vect(vertical, v), new_coord(0,0,0)));
				col = ray_color(ray, &world);
				pixel_col.r += col.r;
				pixel_col.g += col.g;
				pixel_col.b += col.b;
			}
			write_color(data, pixel_col, i, j, samples_per_pixel);
		}
	}
	return (0);
}

int close_window(int keycode, void *arg)
{
    // Realizar cualquier limpieza o liberación de recursos necesarios
	keycode = keycode;
	arg = arg;
    exit(0);
}


int deal_key(int keycode, void *param)
{
	param = param;
	if (keycode == ESC_KEY)
    	exit(0);
	return (0);
}

void	my_mlx_hooks(void *mlx_ptr, void *mlx_win) {
	mlx_hook(mlx_win, 17, 0, close_window, mlx_ptr);
	mlx_key_hook(mlx_win, deal_key, mlx_ptr);
	return ;
}

int paint(t_program *program)
{
    void	*mlx_ptr;
	void	*win_ptr;
	t_data	data;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, RES_WIDTH, RES_HEIGHT, "mlx 42");
	my_mlx_hooks(mlx_ptr, win_ptr);
	data.img = mlx_new_image(mlx_ptr, RES_WIDTH, RES_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	paint_objects(&data, program);	
	mlx_put_image_to_window(mlx_ptr, win_ptr, data.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}