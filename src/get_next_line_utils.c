/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:27:08 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/04/16 21:22:26 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_new_line(t_list *list)
{
	int		i;
	t_list	*last;

	last = list_last(list);
	if (list == NULL)
		return (0);
	i = 0;
	while ((last->content)[i])
	{
		if ((last->content)[i++] == '\n')
			return (1);
	}
	return (0);
}

t_list	*list_last(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*list_new(int readed)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = (char *) malloc(sizeof(char) * (readed + 1));
	if (!(new->content))
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void	list_push(t_list **list, char *buffer, int readed)
{
	int		i;
	t_list	*new;
	t_list	*last;

	new = list_new(readed);
	if (new == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < readed)
	{
		(new->content)[i] = buffer[i];
		i++;
	}
	(new->content)[i] = 0;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last = list_last(*list);
	last->next = new;
}

void	free_list(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
