/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:10:02 by maralons          #+#    #+#             */
/*   Updated: 2023/06/05 14:18:45 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	exit_use(void)
{
	printf("Invalid arguments.\n Usage: ./miniRT [file]\n");
	return (1);
}

void	check_file(char *filename)
{
	check_name(filename);
}

void	check_name(char *filename)
{
	if (filename[strlen(filename) - 1] != 't'
		|| filename[strlen(filename) - 2] != 'r'
		|| filename[strlen(filename) - 3] != '.')
	{
		printf("Invalid file.\n");
		exit(1);
	}
}