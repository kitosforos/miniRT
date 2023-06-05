/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:44:43 by maralons          #+#    #+#             */
/*   Updated: 2023/06/05 14:14:33 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

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
}				t_program;
#endif