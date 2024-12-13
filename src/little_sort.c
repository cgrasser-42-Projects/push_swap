/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:08:42 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 22:10:52 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a, t_list **b)
{
	int	first;
	int	second;
	int	third;

	first = ((t_data *)(*a)->content)->index;
	second = ((t_data *)(*a)->next->content)->index;
	third = ((t_data *)(*a)->next->next->content)->index;
	if (first < second && second > third && third < first)
		rra(a, EXEC_PRINT);
	else if (first > second && second > third)
	{
		sa(a, EXEC_PRINT);
		rra(a, EXEC_PRINT);
	}
	else if (first < second && second > third && third > first)
	{
		pb(a, b, EXEC_PRINT);
		sa(a, EXEC_PRINT);
		pa(b, a, EXEC_PRINT);
	}
	else if (first > second && second < third && third > first)
		sa(a, EXEC_PRINT);
	else
		ra(a, EXEC_PRINT);
}

void	sort_five(t_list **a, t_list **b)
{
	int	size;
	int	i;

	i = 0;
	while (i < 2)
	{
		if (((t_data *)(*a)->content)->index != 0
			&& ((t_data *)(*a)->content)->index != 4)
		{
			pb(a, b, EXEC_PRINT);
			i++;
		}
		else
			ra(a, EXEC_PRINT);
	}
	if (!ft_lst_is_sorted(*a))
		sort_three(a, b);
	optimal_sort(a, b);
	size = ft_lstsize(*a);
	end_sort(a, size);
}
