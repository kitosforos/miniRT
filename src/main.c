/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:44:22 by maralons          #+#    #+#             */
/*   Updated: 2023/06/05 14:41:05 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "error.h"

int	main(int argc, char **argv)
{
	char	*filename;

	if (argc != 2)
		return (exit_use());
	ft_strcpy(filename, argv[1]);
	check_file(filename);
	parse_file(filename);
	return (0);
}
