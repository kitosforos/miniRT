/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:44:43 by maralons          #+#    #+#             */
/*   Updated: 2023/07/07 18:03:31 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

typedef struct s_ray
{
	t_coord origin;
	t_coord direction;
}				t_ray;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct s_amblight
{
	double	ratio;
	t_color	color;
}				t_amblight;

typedef struct s_light
{
	t_coord	coord;
	double	ratio;
	t_color	color;
}				t_light;

typedef struct s_camera
{
	t_coord	coord;
	t_coord	ori;
	double	fov;
}				t_camera;

typedef struct s_sphere
{
	t_coord	coord;
	double	diametre;
	t_color	color;
}				t_sphere;

typedef struct s_plane
{
	t_coord	coord;
	t_coord	dir;
	t_color	color;
}				t_plane;

typedef struct s_cylinder
{
	t_coord	coord;
	t_coord	ori;
	double	diametre;
	double	height;
	t_color	color;
}				t_cylinder;

typedef struct s_program
{
	t_amblight	amblight;
	t_camera	camera;
	t_sphere	spheres[100];
	t_plane		planes[100];
	t_cylinder	cylinders[100];
	t_light		lights[100];
	int			nb[4];
}				t_program;

typedef struct s_hit_record {
    t_coord	p;
    t_coord	normal;
    double	t;
	int		front_face;
	t_color	color;
	t_coord	origin;
}				t_hit_record;

typedef struct	s_hittables {
	t_sphere	*spheres[100];
	int			n_spheres;
}				t_hittables;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

enum {
	SPHERE,
	PLANE,
	CYLINDER,
	LIGHT,
	AMB_LIGHT,
	CAMERA
};
t_coord suma_vect(t_coord vec1, t_coord vec2);
t_coord resta_vect(t_coord vec1, t_coord vec2);
t_coord div_vect(t_coord vec1, double d);
t_coord prod_vect(t_coord vec1, double d);
t_coord new_coord(double x, double y, double z);
t_color new_color(int r, int g, int b);
t_coord unit_vector(t_coord vec);
double dot(const t_coord u, const t_coord v);
t_coord t_f(t_ray ray, double t);
double length_squared(t_coord e);
void set_face_normal(const t_ray r, const t_coord outward_normal, t_hit_record *rec);
int sphere_hit(const t_ray r, double t_min, double t_max, t_hit_record *rec, t_sphere sphere);
int	hit(t_hittables *t, t_ray r, double t_min, double t_max, t_hit_record *rec);
void    add_sphere(t_hittables *world, t_sphere *sphere);
void write_color(t_data *data, t_color pixel_color, int i, int j, int samples_per_pixel);
double randomize();

#endif