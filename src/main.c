/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:59:52 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/12 16:39:04 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print(void *content)
{
	t_data *data = (t_data *)content;
	ft_putnbr_fd(data->value, 1);
	ft_putchar_fd(32, 1);
	ft_putnbr_fd(data->index, 1);
	ft_putchar_fd('\n', 1);
}*/



void	exit_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		size;
	
	argv = ft_parse(argc, argv);
	if (!argv)
		exit_error();
	lst_a = ft_init_lst(argv);
	if (!lst_a)
		exit_error();
	if (ft_lst_is_sorted(lst_a))
		return (ft_lstclear(&lst_a, free), 0);	
	lst_b = NULL;
	size = ft_lstsize(lst_a);
	sort(&lst_a, &lst_b, size, 6);
	ft_lstclear(&lst_a, free);
	return (0);
}
