/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:59:52 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/14 19:15:09 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

static void	select_sort(int size, t_list **lst_a)
{
	t_list	*lst_b;

	lst_b = NULL;
	if (size == 3)
		sort_three(lst_a, &lst_b);
	else if (size == 5)
		sort_five(lst_a, &lst_b);
	else if (size > 300)
		sort(lst_a, &lst_b, size, 6);
	else
		sort(lst_a, &lst_b, size, 0);
}

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	int		size;

	argv = ft_parse(argc, argv);
	if (!argv)
		exit_error();
	lst_a = ft_init_lst(argv);
	if (argc == 2)
		free_tab(argv);
	if (!lst_a)
		exit_error();
	if (ft_lst_is_sorted(lst_a))
		return (ft_lstclear(&lst_a, free), 0);
	size = ft_lstsize(lst_a);
	select_sort(size, &lst_a);
	ft_lstclear(&lst_a, free);
	return (0);
}
