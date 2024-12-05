/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:59:52 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/05 18:40:55 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void	print(void *content)
{
	t_data *data = (t_data *)content;
	ft_putnbr_fd(data->value, 1);
	ft_putchar_fd(32, 1);
	ft_putnbr_fd(data->index, 1);
	ft_putchar_fd('\n', 1);
}*/

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		size;

	lst_a = ft_init_lst(ft_parse(argc, argv));
	if (!lst_a)
		return (ft_putendl_fd("Error", 2), 1);
	lst_b = NULL;
	size = ft_lstsize(lst_a);
	sort(&lst_a, &lst_b, size, 16);
	return (0);
}
