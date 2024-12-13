/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:09:33 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 22:00:12 by cgrasser         ###   ########.fr       */
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

void	ra(t_list **lst_a, int flag)
{
	rotate(lst_a);
	if (flag == EXEC_PRINT)
		ft_printf("ra\n");
}

void	rb(t_list **lst_b, int flag)
{
	rotate(lst_b);
	if (flag == EXEC_PRINT)
		ft_printf("rb\n");
}

void	rr(t_list **lst_a, t_list **lst_b, int flag)
{
	rotate(lst_a);
	rotate(lst_b);
	if (flag == EXEC_PRINT)
		ft_printf("rr\n");
}
