/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:09:33 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 02:43:08 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate(t_list **lst)
{
	t_list	*tmp;

	if (!*lst && !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
}

void	ra(t_list **lst_a)
{
	rotate(lst_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **lst_b)
{
	rotate(lst_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	ft_putendl_fd("rr", 1);
}
