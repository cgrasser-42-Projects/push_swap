/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:58:56 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 22:04:52 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

# define EXEC_PRINT 0
# define EXEC 1

//=============================================================| LIST / DATA |

typedef struct s_data
{
	int	value;
	int	index;
}	t_data;

int		ft_lst_is_sorted(t_list *lst);
t_list	*ft_init_lst(char **values);

//=====================================================================| CMD |

void	pa(t_list **lst_b, t_list **lst_a, int flag);
void	pb(t_list **lst_a, t_list **lst_b, int flag);
void	ra(t_list **lst_a, int flag);
void	rb(t_list **lst_b, int flag);
void	rr(t_list **lst_a, t_list **lst_b, int flag);
void	rra(t_list **lst_a, int flag);
void	rrb(t_list **lst_b, int flag);
void	rrr(t_list **lst_a, t_list **lst_b, int flag);
void	sa(t_list **lst_a, int flag);
void	sb(t_list **lst_b, int flag);
void	ss(t_list **lst_a, t_list **lst_b, int flag);

//===================================================================| PARSE |

char	**ft_parse(int argc, char *argv[]);

//===================================================================| UTILS |

void	free_tab(char **tab);
int		contains_duplicates(int *tab, int size);
int		ft_tablen(char **tab);
void	ft_sort_int_tab(int *tab, int size);
long	ft_atol(const char *str);

#endif
