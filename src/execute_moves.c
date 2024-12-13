/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:36:11 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 22:08:47 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_simple_rotations(t_list **a, t_list **b, t_cost best_move)
{
	while (best_move.cost_b > 0)
	{
		rb(b, EXEC_PRINT);
		best_move.cost_b--;
	}
	while (best_move.cost_b < 0)
	{
		rrb(b, EXEC_PRINT);
		best_move.cost_b++;
	}
	while (best_move.cost_a > 0)
	{
		ra(a, EXEC_PRINT);
		best_move.cost_a--;
	}
	while (best_move.cost_a < 0)
	{
		rra(a, EXEC_PRINT);
		best_move.cost_a++;
	}
}

static void	execute_double_rotations(t_list **a, t_list **b, t_cost best_move)
{
	while (best_move.cost_a > 0 && best_move.cost_b > 0)
	{
		rr(a, b, EXEC_PRINT);
		best_move.cost_a--;
		best_move.cost_b--;
	}
	while (best_move.cost_a < 0 && best_move.cost_b < 0)
	{
		rrr(a, b, EXEC_PRINT);
		best_move.cost_a++;
		best_move.cost_b++;
	}
	execute_simple_rotations(a, b, best_move);
}

void	execute_best_move(t_list **a, t_list **b, t_cost best_move)
{
	execute_double_rotations(a, b, best_move);
	pa(b, a, EXEC_PRINT);
}
