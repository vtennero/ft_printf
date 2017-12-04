/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:30:13 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/13 17:12:50 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_lstempty(t_list *lst)
{
	lst->content = NULL;
	lst->content_size = 0;
	return (lst);
}

static t_list		*ft_lstfill(t_list *lst, void const *content, size_t size)
{
	lst->content = ft_memcpy(lst->content, content, size);
	lst->content_size = size;
	return (lst);
}

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst)
	{
		if (content)
		{
			lst->content = malloc(content_size);
			if (lst->content)
				ft_lstfill(lst, content, content_size);
			else
			{
				free((void *)lst);
				return (NULL);
			}
		}
		else
			ft_lstempty(lst);
		lst->next = NULL;
	}
	return (lst);
}
