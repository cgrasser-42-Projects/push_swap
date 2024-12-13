/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:51:42 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 22:04:21 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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

void	sa(t_list **lst_a, int flag)
{
	swap(lst_a);
	if (flag == EXEC_PRINT)
		ft_printf("sa\n");
}

void	sb(t_list **lst_b, int flag)
{
	swap(lst_b);
	if (flag == EXEC_PRINT)
		ft_printf("sb\n");
}

void	ss(t_list **lst_a, t_list **lst_b, int flag)
{
	swap(lst_a);
	swap(lst_b);
	if (flag == EXEC_PRINT)
		ft_printf("ss\n");
}
