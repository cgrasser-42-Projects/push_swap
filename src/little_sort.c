/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:08:42 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 03:02:56 by cgrasser         ###   ########.fr       */
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
		rra(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first < second && second > third && third > first)
	{
		pb(a, b);
		sa(a);
		pa(b, a);
	}
	else if (first > second && second < third && third > first)
		sa(a);
	else
		ra(a);
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
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	if (!ft_lst_is_sorted(*a))
		sort_three(a, b);
	optimal_sort(a, b);
	size = ft_lstsize(*a);
	end_sort(a, size);
}
