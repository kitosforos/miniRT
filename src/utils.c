/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:12:24 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/06/07 14:23:32 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	ft_atof(char *str)
{
	double	nb;
	double	dec;
	int		i;

	nb = 0;
	dec = 0;
	i = 0;
	while (str[i] && str[i] != '.')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i])
		{
			dec = dec * 10 + (str[i] - '0');
			i++;
		}
	}
	return (nb + dec / pow(10, i));
}

t_color	ft_color_atoi(char *str)
{
	t_color	color;
	int		i;

	i = 0;
	color.r = ft_atof(str);
	while (str[i] && str[i] != ',')
		i++;
	color.g = ft_atof(str + i + 1);
	while (str[i] && str[i] != ',')
		i++;
	color.b = ft_atof(str + i + 1);
	return (color);
}

t_coord	ft_coord_atoi(char *str)
{
	t_coord	coord;
	int		i;

	i = 0;
	coord.x = ft_atof(str);
	while (str[i] && str[i] != ',')
		i++;
	coord.y = ft_atof(str + i + 1);
	while (str[i] && str[i] != ',')
		i++;
	coord.z = ft_atof(str + i + 1);
	return (coord);
}