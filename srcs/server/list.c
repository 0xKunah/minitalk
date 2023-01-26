/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:57:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/25 15:57:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server/minitalk.h"
#include <stdlib.h>

t_list	*ft_lstnew(char content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	while ((*lst) && (*lst)->next)
		(*lst) = (*lst)->next;
	if (*lst)
	{
		(*lst)->next = new;
		*lst = head;
	}
	else
		*lst = new;
}
