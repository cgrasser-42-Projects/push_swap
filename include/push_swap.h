/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:57:47 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 02:47:21 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

//====================================================================| COST |

typedef struct s_cost
{
	int	index_b;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}	t_cost;

//====================================================================| SORT |

void	sort_three(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b, int size, int split);
int		calculate_rotation_cost(int size, int position);
void	optimal_sort(t_list **a, t_list **b);
void	execute_best_move(t_list **a, t_list **b, t_cost best_move);
void	end_sort(t_list **a, int size);

#endif
