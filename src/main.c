/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:44:22 by maralons          #+#    #+#             */
/*   Updated: 2023/06/10 19:49:29 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "error.h"
#include "parse.h"

void	init_prog(t_program *prog)
{
	prog->nb[0] = 0;
	prog->nb[1] = 0;
	prog->nb[2] = 0;
	prog->nb[3] = 0;
}

void	prueba(t_program *program) {
	printf("A %lf %d %d %d\n", program->amblight.ratio, program->amblight.color.r, program->amblight.color.g, program->amblight.color.b);
	printf("C %lf %lf %lf %lf %lf %lf %lf\n", program->camera.coord.x, program->camera.coord.y,
		program->camera.coord.z, program->camera.ori.x, program->camera.ori.y, program->camera.ori.z, program->camera.fov);
	printf("L %lf %lf %lf %lf %d %d %d\n", program->lights[0].coord.x, program->lights[0].coord.y, program->lights[0].coord.z, program->lights[0].ratio, program->lights[0].color.r, program->lights[0].color.g, program->lights[0].color.b);
	printf("pl %lf %lf %lf %lf %lf %lf %d %d %d\n", program->planes[0].coord.x, program->planes[0].coord.y, program->planes[0].coord.z, program->planes[0].dir.x, program->planes[0].dir.y, program->planes[0].dir.z, program->planes[0].color.r, program->planes[0].color.g, program->planes[0].color.b);
	printf("sp %lf %lf %lf %lf %d %d %d\n", program->spheres[0].coord.x, program->spheres[0].coord.y, program->spheres[0].coord.z, program->spheres[0].diametre, program->spheres[0].color.r, program->spheres[0].color.g, program->spheres[0].color.b);
	printf("cy %lf %lf %lf %lf %lf %lf %lf %lf %d %d %d\n", program->cylinders[0].coord.x, program->cylinders[0].coord.y, program->cylinders[0].coord.z, program->cylinders[0].ori.x, program->cylinders[0].ori.y, program->cylinders[0].ori.z, program->cylinders[0].diametre, program->cylinders[0].height, program->cylinders[0].color.r, program->cylinders[0].color.g, program->cylinders[0].color.b);
}

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc != 2)
		return (exit_use());
	init_prog(&program);
	if (check_file(argv[1]) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n file check failed\n", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}

	if (parse_file(argv[1], &program) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n file parsing failed\n", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	prueba(&program);
	return (EXIT_SUCCESS);
}
