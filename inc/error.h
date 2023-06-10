/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:11:38 by maralons          #+#    #+#             */
/*   Updated: 2023/06/10 18:19:39 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

int		exit_use(void);
int		check_file(char *filename);
int		check_name(char *filename);


#endif