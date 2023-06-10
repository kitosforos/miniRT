/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:11:38 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/06/10 18:44:35 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "rt.h"

double	ft_atof(char *str);
t_color	ft_color_atoi(char *str);
t_coord	ft_coord_atoi(char *str);
void	ft_split_free(char **splitted);

#endif