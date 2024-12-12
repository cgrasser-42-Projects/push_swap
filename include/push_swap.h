/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:57:47 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 00:21:54 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "cmd.h"

//=============================================================| LIST / DATA |

typedef struct s_data
{
	int	value;
	int	index;
}	t_data;

typedef struct s_cost
{
	int	index_b;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}	t_cost;

//===================================================================| PARSE |

char	**ft_parse(int argc, char *argv[]);
t_list	*ft_init_lst(char **values);

//====================================================================| SORT |

int		ft_lst_is_sorted(t_list *lst);
void	sort_three(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b, int size, int split);
int		calculate_rotation_cost(int size, int position);
void	optimal_sort(t_list **a, t_list **b);
void	execute_best_move(t_list **a, t_list **b, t_cost best_move);
void	end_sort(t_list **a, int size);

//===================================================================| UTILS |

void	free_tab(char **tab);
int		contains_duplicates(int *tab, int size);
int		ft_tablen(char **tab);
void	ft_sort_int_tab(int *tab, int size);
long	ft_atol(const char *str);

#endif
