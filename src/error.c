/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:10:02 by maralons          #+#    #+#             */
/*   Updated: 2023/06/07 13:08:16 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	exit_use(void)
{
	printf("Invalid arguments.\n Usage: ./miniRT [file]\n");
	return (1);
}

int	check_file(char *filename)
{
	if (check_name(filename) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_name(char *filename)
{
	if (filename[strlen(filename) - 1] != 't'
		|| filename[strlen(filename) - 2] != 'r'
		|| filename[strlen(filename) - 3] != '.')
	{
		printf("Invalid file.\n");
		return (EXIT_FAILURE);
	}
}