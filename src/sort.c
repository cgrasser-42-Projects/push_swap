/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:35:34 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/04 18:33:35 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pre_sort(t_list **a, t_list **b, int *limits)
{
	int i;
	int index_a;

	i = 0;
	while (i < limits[1] - limits[2])
	{
		index_a = ((t_data *)((*a)->content))->index;
		if (index_a >= limits[0] && index_a < limits[1])
			pb(a,b);
		else if (index_a < limits[0] && index_a >= limits[2])
		{
			pb(a,b);
			rb(b);
		}
		else
			ra(a);
	}
}

int	*set_limits(int min, int mediane, int max)
{
	int	limits[3];

	limits[0] = min;
	limites[1] = mediane;
	limits[2] = max;
	return (limits);
}

void	sort(t_list **a, t_list **b, int size)
{
	pre_sort(a, b, set_limits(3 * (size / 8), size / 2, 5 * (size / 8));
	pre_sort(a, b, set_limits(2 * (size / 8), size / 2, 6 * (size / 8));
	pre_sort(a, b, set_limits(size / 8, size / 2, 7 * (size / 8));
	pre_sort(a, b, set_limits(0, size / 2, size);
}
