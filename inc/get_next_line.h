/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:24:23 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/04/18 18:20:11 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	5
# endif

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

void	read_into_list(int fd, t_list **list);
char	*get_next_line(int fd);
char	*get_linee(t_list *list);
char	*alloc_line(t_list *list);
void	list_push(t_list **list, char *buffer, int readed);
t_list	*list_new(int readed);
t_list	*list_last(t_list *lst);
int		has_new_line(t_list *list);
void	free_list(t_list *list);
void	clean_list(t_list **list);
#endif