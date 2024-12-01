/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:05:52 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/01 16:22:53 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_data	*ft_datanew(int value)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->value = value;
	data->index = -1;
	return (data);
}

static int	ft_data_index(int value, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (value == tab[i])
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_lst_data_index(t_list *lst, int *tab)
{
	int	size;

	size = ft_lstsize(lst);
	while (lst)
	{
		((t_data *)lst->content)->index
			= ft_data_index(((t_data *)lst->content)->value, tab, size);
		lst = lst->next;
	}
}

t_list	*ft_init_lst(char **values)
{
	t_list	*lst;
	t_data	*data;
	int		value;
	int		*tab;
	int		i;

	if (!values)
		return (NULL);
	tab = (int *)malloc(ft_tablen(values) * sizeof(int));
	lst = NULL;
	i = 0;
	while (values[i])
	{
		value = ft_atoi(values[i]);
		tab[i] = value;
		data = ft_datanew(value);
		ft_lstadd_back(&lst, ft_lstnew(data));
		i++;
	}
	ft_sort_int_tab(tab, i);
	ft_lst_data_index(lst, tab);
	return (lst);
}
