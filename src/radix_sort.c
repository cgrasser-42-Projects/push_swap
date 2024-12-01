/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:58:16 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/01 16:11:57 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(int size)
{
	int	max_value;
	int	max_bits;

	max_value = size - 1;
	max_bits = 0;
	while (max_value >> max_bits)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **a, t_list **b, int size)
{
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = get_max_bits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((((t_data *)((*a)->content))->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(b, a);
		i++;
	}
}
