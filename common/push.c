/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:43:21 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 02:42:24 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	push(t_list **lst_one, t_list **lst_two)
{
	t_list	*tmp;

	if (*lst_one)
	{
		tmp = *lst_one;
		*lst_one = (*lst_one)->next;
		tmp->next = *lst_two;
		*lst_two = tmp;
	}
}

void	pa(t_list **lst_b, t_list **lst_a)
{
	push(lst_b, lst_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	push(lst_a, lst_b);
	ft_putendl_fd("pb", 1);
}
