/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:35:34 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/04 20:44:08 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_max_index(t_list *list)
{
    int max_index = ((t_data *)(list->content))->index;
    list = list->next;
    while (list)
    {
        int current_index = ((t_data *)(list->content))->index;
        if (current_index > max_index)
            max_index = current_index;
        list = list->next;
    }
    return max_index;
}

void	end_sort(t_list **a)
{
	int	last_index_a;
	int max_index_a;

	max_index_a = get_max_index(*a);
	while (*a)
	{
		last_index_a = ((t_data *)(ft_lstlast(*a)->content))->index;
		if (last_index_a != max_index_a)
			rra(a);
		else
			break ;
	}
}


void	final_sort(t_list **a, t_list **b)
{
	int	index_a;
	int index_b;
	int last_index_a;
	int max_index_a;

	max_index_a = get_max_index(*a);
	while (*b)
	{
		index_a = ((t_data *)((*a)->content))->index;
		index_b = ((t_data *)((*b)->content))->index;
		last_index_a = ((t_data *)(ft_lstlast(*a)->content))->index;
		if (index_a > index_b && last_index_a < index_b)
			pa(b, a);
		else if (index_a > index_b && last_index_a == max_index_a)
			pa(b, a);
		else if (index_a < index_b && index_b > max_index_a && last_index_a == max_index_a)
		{
			pa(b, a);
			ra(a);
			max_index_a = index_b;
		}
		else if (index_a < index_b)
			ra(a);
		else
			rra(a);
	}
}

void	pre_sort(t_list **a, t_list **b, int *limits)
{
	int i;
	int index_a;

	i = ft_lstsize(*b);
	while (i < (limits[2] - limits[0]) && *a)
	{
		index_a = ((t_data *)((*a)->content))->index;
		if (index_a >= limits[1] && index_a < limits[2])
		{
			pb(a,b);
			i++;
		}
		else if (index_a < limits[1] && index_a >= limits[0])
		{
			pb(a,b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

int	*set_limits(int *limits, int min, int mediane, int max)
{
	limits[0] = min;
	limits[1] = mediane;
	limits[2] = max;
	return (limits);
}

void	sort(t_list **a, t_list **b, int size)
{
	int *limits = (int *)malloc(3 * sizeof(int));
	if (!limits)
		return ;
	pre_sort(a, b, set_limits(limits, 3 * (size / 8), size / 2, 5 * (size / 8)));
	pre_sort(a, b, set_limits(limits, 2 * (size / 8), size / 2, 6 * (size / 8)));
	pre_sort(a, b, set_limits(limits, size / 8, size / 2, 7 * (size / 8)));
	pre_sort(a, b, set_limits(limits, 0, size / 2, size));
	free(limits);
	pa(b,a);
	pa(b,a);
	final_sort(a, b);
	end_sort(a);
}
