/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:44:22 by maralons          #+#    #+#             */
/*   Updated: 2023/06/05 14:16:13 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "error.h"

int main(int argc, char **argv)
{
	char	*filename;

	if (argc != 2)
		return (exit_use());
	strcpy(filename, argv[1]);
	check_file(filename);
	return (0);
}
