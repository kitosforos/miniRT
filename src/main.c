/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:44:22 by maralons          #+#    #+#             */
/*   Updated: 2023/06/07 13:21:27 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "error.h"

int	main(int argc, char **argv)
{
	char		*filename;
	t_program	program;

	if (argc != 2)
		return (exit_use());
	if (ft_strcpy(filename, argv[1]) == NULL)
	{
		ft_putstr("Error: filename copy failed\n");
		return (EXIT_FAILURE);
	}
	if (check_file(filename) == EXIT_FAILURE)
	{
		ft_putstr("Error: file check failed\n");
		return (EXIT_FAILURE);
	}
	if (parse_file(filename, &program) == EXIT_FAILURE)
	{
		ft_putstr("Error: file parsing failed\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
