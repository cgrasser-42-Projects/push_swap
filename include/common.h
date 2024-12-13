/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:58:56 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 02:31:24 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"

//=============================================================| LIST / DATA |

typedef struct s_data
{
	int	value;
	int	index;
}	t_data;

int		ft_lst_is_sorted(t_list *lst);
t_list	*ft_init_lst(char **values);

//=====================================================================| CMD |

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

//===================================================================| PARSE |

char	**ft_parse(int argc, char *argv[]);

//===================================================================| UTILS |

void	free_tab(char **tab);
int		contains_duplicates(int *tab, int size);
int		ft_tablen(char **tab);
void	ft_sort_int_tab(int *tab, int size);
long	ft_atol(const char *str);

#endif
