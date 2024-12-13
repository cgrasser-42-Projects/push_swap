/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:05:52 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/13 02:41:40 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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

int	ft_lst_is_sorted(t_list *lst)
{
	t_list	*current;
	t_list	*next_node;

	current = lst;
	next_node = NULL;
	while (current && current->next)
	{
		next_node = current->next;
		if (((t_data *)current->content)->index
			> ((t_data *)next_node->content)->index)
			return (0);
		current = current->next;
	}
	return (1);
}

t_list	*ft_init_lst(char **values)
{
	t_list	*lst;
	t_data	*data;
	long	value;
	int		*tab;
	int		i;

	tab = (int *)malloc(ft_tablen(values) * sizeof(int));
	lst = NULL;
	i = 0;
	while (values[i])
	{
		value = ft_atol(values[i]);
		if (value > 2147483647 || value < -2147483648)
			return (free(tab), ft_lstclear(&lst, free), NULL);
		tab[i++] = (int)value;
		data = ft_datanew((int)value);
		ft_lstadd_back(&lst, ft_lstnew(data));
	}
	ft_sort_int_tab(tab, i);
	if (contains_duplicates(tab, i))
		return (free(tab), ft_lstclear(&lst, free), NULL);
	ft_lst_data_index(lst, tab);
	return (free(tab), lst);
}
