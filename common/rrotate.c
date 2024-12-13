/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:23:18 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 02:43:25 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	rrotate(t_list **lst)
{
	t_list	*last;
	t_list	*second_last;

	if (!*lst || !(*lst)->next)
		return ;
	last = ft_lstlast(*lst);
	second_last = *lst;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	rra(t_list **lst_a)
{
	rrotate(lst_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **lst_b)
{
	rrotate(lst_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rrotate(lst_a);
	rrotate(lst_b);
	ft_putendl_fd("rrr", 1);
}
