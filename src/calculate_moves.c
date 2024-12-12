/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:56:12 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/12 14:24:36 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_cost(int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		if (a > b)
			return (a);
		return (b);
	}
	if (a < 0 && b < 0)
	{
		if (a < b)
			return (-a);
		return (-b);
	}
	if (a < 0)
		return (-a + b);
	return (-b + a);
}

int	calculate_rotation_cost(int size, int position)
{
	if (position <= size / 2)
		return (position);
	return (-(size - position));
}

static int	find_position_in_a(t_list *a, int index_b)
{
	int	pos;
	int	first_index;
	int	last_index;
	int	current_index;
	int	next_index;

	pos = 0;
	first_index = ((t_data *)(a->content))->index;
	last_index = ((t_data *)(ft_lstlast(a)->content))->index;
	if (index_b < first_index && index_b > last_index)
		return (0);
	while (a->next)
	{
		current_index = ((t_data *)(a->content))->index;
		next_index = ((t_data *)(a->next->content))->index;
		if (index_b > current_index && index_b < next_index)
			break ;
		a = a->next;
		pos++;
	}
	return (pos + 1);
}

t_cost	calculate_best_move(t_list *a, t_list *b)
{
	t_cost	best_move;
	t_cost	tmp_move;
	int		pos[2];
	int		size_b;
	int		size_a;

	best_move.total_cost = INT_MAX;
	pos[0] = 0;
	pos[1] = 0;
	size_b = ft_lstsize(b);
	size_a = ft_lstsize(a);
	while (b)
	{
		tmp_move.index_b = ((t_data *)(b->content))->index;
		tmp_move.cost_b = calculate_rotation_cost(size_b, pos[1]);
		pos[0] = find_position_in_a(a, tmp_move.index_b);
		tmp_move.cost_a = calculate_rotation_cost(size_a, pos[0]);
		tmp_move.total_cost = count_cost(tmp_move.cost_a, tmp_move.cost_b);
		if (tmp_move.total_cost < best_move.total_cost)
			best_move = tmp_move;
		b = b->next;
		pos[1]++;
	}
	return (best_move);
}
