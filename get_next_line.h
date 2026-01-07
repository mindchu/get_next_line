/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:19:10 by chutterm          #+#    #+#             */
/*   Updated: 2026/01/07 21:01:23 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_gnl
{
	char			*content;
	int				len;
	struct s_gnl	*next;
}					t_gnl;

char	*get_next_line(int fd);
t_gnl	*gnl_lstnew(char *content);
t_gnl	*gnl_lstlast(t_gnl *lst);
void	gnl_lstadd_back(t_gnl **lst, t_gnl *new);
void	gnl_lstclear(t_gnl **lst);
void	*gnl_calloc(size_t nmemb, size_t size);

#endif