/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:59:52 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/29 18:52:51 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}


int	main(int argc, char *argv[])
{
	int *tab = malloc(argc * sizeof(int));
	int	i;
	i = 0;
	while (argv[i + 1])
	{
		tab[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_sort_int_tab(tab, i);
	int j = 0;
	while (j < i)
	{
		ft_putnbr_fd(tab[j++], 1);
		ft_putchar_fd(32, 1);
	}
}
