/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:23:18 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 22:02:30 by cgrasser         ###   ########.fr       */
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

void	rra(t_list **lst_a, int flag)
{
	rrotate(lst_a);
	if (flag == EXEC_PRINT)
		ft_printf("rra\n");
}

void	rrb(t_list **lst_b, int flag)
{
	rrotate(lst_b);
	if (flag == EXEC_PRINT)
		ft_printf("rrb\n");
}

void	rrr(t_list **lst_a, t_list **lst_b, int flag)
{
	rrotate(lst_a);
	rrotate(lst_b);
	if (flag == EXEC_PRINT)
		ft_printf("rrr\n");
}
