/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:57:47 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/12 16:36:53 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>

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

t_list	*ft_init_lst(char **values);
int ft_lst_is_sorted(t_list *lst);

//==================================================================|        |

int		calculate_rotation_cost(int size, int position);
t_cost	calculate_best_move(t_list *a, t_list *b);
void	execute_best_move(t_list **a, t_list **b, t_cost best_move);

//===================================================================| PARSE |

char	**ft_parse(int argc, char *argv[]);

//===================================================================| RADIX |

void	sort(t_list **a, t_list **b, int size, int split);

//=================================================================| COMMAND |

void	pa(t_list **lst_b, t_list **lst_a);
void	pb(t_list **lst_a, t_list **lst_b);
void	ra(t_list **lst_a);
void	rb(t_list **lst_b);
void	rr(t_list **lst_a, t_list **lst_b);
void	rra(t_list **lst_a);
void	rrb(t_list **lst_b);
void	rrr(t_list **lst_a, t_list **lst_b);
void	sa(t_list **lst_a);
void	sb(t_list **lst_b);
void	ss(t_list **lst_a, t_list **lst_b);

//===================================================================| UTILS |


int		contains_duplicates(int *tab, int size);
int		ft_tablen(char **tab);
void	ft_sort_int_tab(int *tab, int size);
long	ft_atol(const char *str);

#endif
