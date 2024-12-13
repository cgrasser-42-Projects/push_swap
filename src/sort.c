/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:35:34 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 22:10:11 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_position(t_list *a)
{
	int	i;
	int	index_a;

	i = 0;
	while (a)
	{
		index_a = ((t_data *)(a->content))->index;
		if (index_a == 0)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	end_sort(t_list **a, int size)
{
	int	cost;

	cost = calculate_rotation_cost(size, get_min_position(*a));
	while (cost > 0)
	{
		ra(a, EXEC_PRINT);
		cost--;
	}
	while (cost < 0)
	{
		rra(a, EXEC_PRINT);
		cost++;
	}
}

static void	pre_sort_rr(t_list **a, t_list **b, int *limits)
{
	int	index_a_next;

	pb(a, b, EXEC_PRINT);
	index_a_next = ((t_data *)((*a)->content))->index;
	if (!(index_a_next >= limits[1] && index_a_next < limits[2])
		&& !(index_a_next < limits[1] && index_a_next >= limits[0]))
		rr(a, b, EXEC_PRINT);
	else
		rb(b, EXEC_PRINT);
}

static void	pre_sort(t_list **a, t_list **b, int *limits)
{
	int	i;
	int	index_a;

	i = ft_lstsize(*b);
	while (i < (limits[2] - limits[0]) && *a)
	{
		index_a = ((t_data *)((*a)->content))->index;
		if (index_a >= limits[1] && index_a < limits[2])
		{
			pb(a, b, EXEC_PRINT);
			i++;
		}
		else if (index_a < limits[1] && index_a >= limits[0])
		{
			pre_sort_rr(a, b, limits);
			i++;
		}
		else
			ra(a, EXEC_PRINT);
	}
}

void	sort(t_list **a, t_list **b, int size, int split)
{
	int	min;
	int	max;
	int	*limits;

	min = split / 2 - 1;
	max = split / 2 + 1;
	limits = (int *)malloc(3 * sizeof(int));
	limits[1] = size / 2;
	while (max < split)
	{
		limits[0] = min * (size / split);
		limits[2] = max * (size / split);
		pre_sort(a, b, limits);
		max++;
		min--;
	}
	limits[0] = 1;
	limits[2] = size -1;
	pre_sort(a, b, limits);
	free(limits);
	optimal_sort(a, b);
	end_sort(a, size);
}
