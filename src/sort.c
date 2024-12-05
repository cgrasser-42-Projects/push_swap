/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:35:34 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/05 18:41:43 by cgrasser         ###   ########.fr       */
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

void 	sort(t_list **a, t_list **b, int size, int split)
{
	int min;
	int max;
	int	*limits;

	min = split / 2 - 1;
	max = split / 2 + 1;
	limits = (int *)malloc(3 * sizeof(int));
	if (!limits)
		return ;
	limits[1] = size / 2;
	while (max < split)
	{
		limits[0] = min * (size / split);
		limits[2] = max * (size / split);
		pre_sort(a, b, limits);
		max++;
		min--;
	}
	limits[0] = 0;
	limits[2] = size;
	pre_sort(a, b, limits);
	free(limits);
	//pa(b,a);
	//pa(b,a);
	//final_sort(a, b);
	//end_sort(a);
}

/*avoid	sort(t_list **a, t_list **b, int size)
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
}*/
