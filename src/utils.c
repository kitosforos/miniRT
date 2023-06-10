/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:12:24 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/06/10 19:19:46 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	ft_atof(char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res >= 0)
		return (res + res2);
	else
		return (res + -res2);
}

t_color	ft_color_atoi(char *str)
{
	t_color	color;
	int		i;

	i = 0;
	color.r = ft_atof(str);
	while (str[i] && str[i] != ',')
		i++;
	color.g = ft_atof(str + ++i);
	while (str[i] && str[i] != ',')
		i++;
	color.b = ft_atof(str + ++i);
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
	coord.y = ft_atof(str + ++i);
	while (str[i] && str[i] != ',')
		i++;
	coord.z = ft_atof(str + ++i);
	return (coord);
}

void	ft_split_free(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}