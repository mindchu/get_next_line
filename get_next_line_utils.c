/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:19:18 by chutterm          #+#    #+#             */
/*   Updated: 2026/01/07 21:01:06 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*gnl_lstnew(char *content)
{
	t_gnl	*elem;

	elem = malloc(sizeof(t_gnl));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->len = 0;
	elem->next = NULL;
	return (elem);
}

t_gnl	*gnl_lstlast(t_gnl *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	gnl_lstadd_back(t_gnl **lst, t_gnl *new)
{
	t_gnl	*temp;

	if (*lst)
	{
		temp = gnl_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

void	gnl_lstclear(t_gnl **lst)
{
	t_gnl	*temp_lst;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp_lst = *lst;
		*lst = (*lst)->next;
		free(temp_lst->content);
		free(temp_lst);
	}
	*lst = NULL;
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void			*arr;
	size_t			alloc_size;
	size_t			i;
	unsigned char	*cast_s;

	alloc_size = nmemb * size;
	if (!alloc_size || alloc_size / nmemb != size)
		return (NULL);
	arr = malloc(alloc_size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	cast_s = arr;
	while (i < alloc_size)
	{
		cast_s[i] = '\0';
		i++;
	}
	return (cast_s);
}
