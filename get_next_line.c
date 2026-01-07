/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:19:14 by chutterm          #+#    #+#             */
/*   Updated: 2025/12/19 21:11:45 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_new_line(t_list *lst)
{
	int	index;

	lst = ft_lstlast(lst);
	if (!lst)
		return (0);
	index = 0;
	while (lst->content[index] != '\0')
	{
		if (lst->content[index] == '\n')
		{
			lst->len = ++index;
			return (1);
		}
		index++;
	}
	lst->len = index;
	return (0);
}

static void	read_line(t_list **lst, int fd)
{
	int		result;
	char	*buf;
	t_list	*temp;

	result = 0;
	while (!is_new_line(*lst))
	{
		buf = NULL;
		temp = ft_lstnew(buf);
		temp->content = ft_calloc(sizeof(*buf), (BUFFER_SIZE + 1));
		result = read(fd, temp->content, BUFFER_SIZE);
		if (result <= 0)
		{
			free(temp->content);
			free(temp);
			return ;
		}
		temp->content[BUFFER_SIZE] = '\0';
		ft_lstadd_back(lst, temp);
	}
}

static void	create_line(t_list *lst, char **next_line)
{
	int		size;
	int		i;
	t_list	*temp;

	temp = lst;
	size = 0;
	while (temp)
	{
		size = size + temp->len;
		temp = temp->next;
	}
	if (!size)
		return ;
	*next_line = malloc(sizeof(**next_line) * (size + 1));
	if (!next_line)
		return ;
	size = 0;
	while (lst && lst->content)
	{
		i = 0;
		while (lst->content[i] && i < lst->len)
			(*next_line)[size++] = lst->content[i++];
		lst = lst->next;
	}
	(*next_line)[size] = '\0';
}

static void	update_line(t_list **lst)
{
	t_list	*temp;
	t_list	*new_node;
	char	*content;
	int		i;
	int		size;

	size = 0;
	temp = ft_lstlast(*lst);
	if (!temp)
		return ;
	content = temp->content;
	size = temp->len;
	temp->content = NULL;
	ft_lstclear(lst);
	i = 0;
	if (content[size] != '\0')
	{
		while (content[size] != '\0')
			content[i++] = content[size++];
		content[i] = '\0';
		new_node = ft_lstnew(content);
		ft_lstadd_back(lst, new_node);
	}
	else
		free(content);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*next_line;

	next_line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(&lst, fd);
	if (!lst)
		return (NULL);
	create_line(lst, &next_line);
	update_line(&lst);
	return (next_line);
}
