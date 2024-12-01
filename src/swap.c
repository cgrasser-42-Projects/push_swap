/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:51:42 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/01 16:17:06 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void	sa(t_list **lst_a)
{
	swap(lst_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **lst_b)
{
	swap(lst_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	ft_putendl_fd("ss", 1);
}
