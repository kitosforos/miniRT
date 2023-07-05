/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:44:43 by maralons          #+#    #+#             */
/*   Updated: 2023/07/04 13:46:22 by danicn           ###   ########.fr       */
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
double	hit_sphere(const t_coord center, double radius, const t_ray r);
t_coord t_f(t_ray ray, double t);

#endif