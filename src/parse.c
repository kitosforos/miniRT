/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:35:48 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/06/05 14:46:33 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	new_object(char *object) {
	if (object[0] == 'R')
		new_resolution(object);
	else if (object[0] == 'A')
		new_ambient_light(object);
	else if (object[0] == 'c')
		new_camera(object);
	else if (object[0] == 'l')
		new_light(object);
	else if (object[0] == 's')
		new_sphere(object);
	else if (object[0] == 'p')
		new_plane(object);
	else if (object[0] == 's')
		new_square(object);
	else if (object[0] == 'c')
		new_cylinder(object);
	else if (object[0] == 't')
		new_triangle(object);
	else
		printf("Error\n");
}

void	parse_file(char *filename) {
	int		fd;
	char	*line;
	int		ret;

	fd = open(filename, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		new_object(line);
		free(line);
	}
	if (ret == -1)
		printf("Error\n");
	close(fd);
}