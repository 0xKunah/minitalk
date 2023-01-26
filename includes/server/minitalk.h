/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:12:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/18 12:12:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(char content);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif