/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:33 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/04/16 21:24:12 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_list(t_list **list)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (list == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = list_last(*list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(((strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_list(*list);
	*list = clean_node;
}

char	*alloc_line(t_list *list)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	while (list)
	{
		i = 0;
		while ((list->content)[i] && (list->content)[i] != '\n')
			i++;
		len += i;
		if ((list->content)[i] == '\n')
			i++;
		list = list->next;
	}
	line = (char *) malloc(sizeof(char) * (len + 2));
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*get_linee(t_list *list)
{
	int		i;
	int		j;
	char	*line;

	line = alloc_line(list);
	if (line == NULL)
		return (NULL);
	j = 0;
	while (list)
	{
		i = 0;
		while ((list->content)[i] && (list->content)[i] != '\n')
			line[j++] = (list->content)[i++];
		if ((list->content)[i] == '\n')
			line[j++] = (list->content)[i++];
		list = list->next;
	}
	line[j] = 0;
	return (line);
}

void	read_into_list(int fd, t_list **list)
{
	char	*buffer;
	int		readed;

	if (fd < 0 || list == NULL)
		return ;
	readed = 1;
	while (!has_new_line(*list) && readed)
	{
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		readed = (int)read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buffer);
			return ;
		}
		buffer[readed] = 0;
		list_push(list, buffer, readed);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*list = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_into_list(fd, &list);
	if (list == NULL)
		return (NULL);
	line = get_linee(list);
	if (line == NULL)
		return (NULL);
	clean_list(&list);
	if (line[0] == '\0')
	{
		free_list(list);
		list = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*a;
// 	fd = open("ex.txt", O_RDONLY);
// 	a = get_next_line(fd);
// 	printf("%s", a);
// 	free(a);
// 	a = get_next_line(fd);
// 	printf("%s", a);
// 	free(a);
// 	a = get_next_line(fd);
// 	printf("%s", a);
// 	free(a);
// 	a = get_next_line(fd);
// 	printf("%s", a);
// 	free(a);
// 	close(fd);
// 	// t_list	*list = NULL;
// 	// char buf[] = "buenas";
// 	// list_push(&list, buf, 6);
// 	// list_push(&list, "hola", 4);
// 	// printf("%s", list->content);
// 	// printf("%s", list->content);

// }