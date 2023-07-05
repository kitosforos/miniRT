/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:12:24 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/07/04 17:23:20 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "paint.h"
#include "rt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_color	ray_color(t_ray ray)
{
	double t;
	
	t = hit_sphere(new_coord(0,0,-1), 0.5, ray);
	if (t > 0.0)
	{
		t_coord u = unit_vector(resta_vect(t_f(ray, t), new_coord(0,0,-1)));
		return (new_color((0.5 * (u.x + 1)) * 255, (0.5 * (u.y + 1)) * 255, (0.5 * (u.z + 1)) * 255));
	}
	t_coord unt = unit_vector(ray.direction);
	t = 0.5*(unt.y+1.0);
	return (new_color((1.0-t)*255 + t*0.5*255, (1.0-t)*255 + t*0.7*255, (1.0-t)*255 + t*255));
}

int	paint_objects(t_data *data, t_program *program) 
{
	int		i;
	int		j;
	double	u;
	double	v;
	t_ray	ray;
	t_color	col;
	program = program;
	double viewport_height = 2, viewport_width = viewport_height * (16.0/9.0);
	t_coord horizontal = new_coord(viewport_width, 0, 0);
	t_coord vertical = new_coord(0, viewport_height, 0);
	t_coord lower_left_corner = resta_vect(resta_vect(new_coord(0,0,0), div_vect(horizontal, 2)), resta_vect(div_vect(vertical, 2), new_coord(0,0,1)));
	for (j = RES_HEIGHT - 1; j >= 0; j--)
	{
		for (i = 0; i < RES_WIDTH; ++i)
		{
			u = (double)i / (RES_WIDTH - 1);
			v = (double)j / (RES_HEIGHT - 1);
			ray.origin = new_coord(0,0,0);
			ray.direction = suma_vect(suma_vect(lower_left_corner, prod_vect(horizontal, u)), resta_vect(prod_vect(vertical, v), new_coord(0,0,0)));
			col = ray_color(ray);
			my_mlx_pixel_put(data, i, j, (col.r << 16) | (col.g << 8) | (col.b));
			
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