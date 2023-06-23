/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:35:48 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/06/21 15:21:50 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	new_ambient_light(char **splitted, t_program *program)
{
	t_amblight	ambient_light;
	t_color		color;

	color = ft_color_atoi(splitted[2]);
	ambient_light.color = color;
	ambient_light.ratio = ft_atof(splitted[1]);
	program->amblight = ambient_light;
	return (EXIT_SUCCESS);
}

int	new_camera(char **splitted, t_program *program)
{
	t_camera	camera;

	camera.coord = ft_coord_atoi(splitted[1]);
	camera.ori = ft_coord_atoi(splitted[2]);
	camera.fov = ft_atof(splitted[3]);
	program->camera = camera;
	return (EXIT_SUCCESS);
}

int	new_light(char **splitted, t_program *program)
{
	t_light	light;

	light.coord = ft_coord_atoi(splitted[1]);
	light.color = ft_color_atoi("255,255,255");
	light.ratio = ft_atof(splitted[2]);
	program->lights[program->nb[LIGHT]++] = light;
	return (EXIT_SUCCESS);
}

int	new_sphere(char **splitted, t_program *program)
{
	t_sphere	sphere;

	sphere.coord = ft_coord_atoi(splitted[1]);
	sphere.diametre = ft_atof(splitted[2]);
	sphere.color = ft_color_atoi(splitted[3]);
	program->spheres[program->nb[SPHERE]++] = sphere;
	return (EXIT_SUCCESS);
}

int	new_plane(char **splitted, t_program *program)
{
	t_plane	plane;

	plane.coord = ft_coord_atoi(splitted[1]);
	plane.dir = ft_coord_atoi(splitted[2]);
	plane.color = ft_color_atoi(splitted[3]);
	program->planes[program->nb[PLANE]++] = plane;
	return (EXIT_SUCCESS);
}

int	new_cylinder(char **splitted, t_program *program)
{
	t_cylinder	cylinder;

	cylinder.coord = ft_coord_atoi(splitted[1]);
	cylinder.ori = ft_coord_atoi(splitted[2]);
	cylinder.diametre = ft_atof(splitted[3]);
	cylinder.height = ft_atof(splitted[4]);
	cylinder.color = ft_color_atoi(splitted[5]);
	program->cylinders[program->nb[CYLINDER]++] = cylinder;
	return (EXIT_SUCCESS);
}

int	new_object(char *object, t_program *program)
{
	char	**splitted;

	splitted = ft_split(object, ' ');
	if (!splitted)
		return (EXIT_FAILURE);
	if (line_errors(splitted))
		return (EXIT_FAILURE);
	if (object[0] == 'A' && new_ambient_light(splitted, program))
		return (EXIT_FAILURE);
	else if (object[0] == 'C' && new_camera(splitted, program))
		return (EXIT_FAILURE);
	else if (object[0] == 'L' && new_light(splitted, program))
		return (EXIT_FAILURE);
	else if (object[0] == 's' && new_sphere(splitted, program))
		return (EXIT_FAILURE);
	else if (object[0] == 'p' && new_plane(splitted, program))
		return (EXIT_FAILURE);
	else if (object[0] == 'c' && new_cylinder(splitted, program))
		return (EXIT_FAILURE);
	ft_split_free(splitted);
	return (EXIT_SUCCESS);
}

int	line_errors(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i][0] != 'A' && str[i][0] != 'C' && str[i][0] != 'L' 
			&& str[i][0] != 's' && str[i][0] != 'p' && str[i][0] != 'c')
			return (EXIT_FAILURE);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (i > 0 && (str[i][j] < '0' || str[i][j] > '9') && str[i][j] != '\n'
				&& str[i][j] != '.' && str[i][j] != ',' && str[i][j] != '-')
			{
				printf("char: %c\n", str[i][j]);
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parse_file(char *filename, t_program *program)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{		
		if (line[0] != '\n')
		{
			if (new_object(line, program))
				return (EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (EXIT_SUCCESS);
}
//ERRORES: caracteres no validos, no hay A C L, parametros insuficientes en cada objeto del split, objetos incorrectos, ACL duplicados, demasiados pl sp o cy