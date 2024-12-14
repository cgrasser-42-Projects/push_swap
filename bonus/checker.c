/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:58:44 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/14 18:20:00 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	free_lst(t_list **a, t_list **b)
{
	if (*a)
		ft_lstclear(a, free);
	if (*b)
		ft_lstclear(b, free);
}

int	exec_moves(char *move, t_list **a, t_list **b)
{
	if (!ft_strcmp(move, "pa\n"))
		return (pa(b, a, EXEC), 1);
	if (!ft_strcmp(move, "pb\n"))
		return (pb(a, b, EXEC), 1);
	if (!ft_strcmp(move, "ra\n"))
		return (ra(a, EXEC), 1);
	if (!ft_strcmp(move, "rb\n"))
		return (rb(b, EXEC), 1);
	if (!ft_strcmp(move, "rr\n"))
		return (rr(a, b, EXEC), 1);
	if (!ft_strcmp(move, "rra\n"))
		return (rra(a, EXEC), 1);
	if (!ft_strcmp(move, "rrb\n"))
		return (rrb(b, EXEC), 1);
	if (!ft_strcmp(move, "rrr\n"))
		return (rrr(a, b, EXEC), 1);
	if (!ft_strcmp(move, "sa\n"))
		return (sa(a, EXEC), 1);
	if (!ft_strcmp(move, "sb\n"))
		return (sb(b, EXEC), 1);
	if (!ft_strcmp(move, "ss\n"))
		return (ss(a, b, EXEC), 1);
	else
		return (0);
}

void	read_exec_stdin(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (!exec_moves(line, a, b))
		{
			free_lst(a, b);
			free(line);
			exit_error();
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (ft_lst_is_sorted(*a) && ft_lstsize(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;

	argv = ft_parse(argc, argv);
	if (!argv)
		exit_error();
	lst_a = ft_init_lst(argv);
	if (argc == 2)
		free_tab(argv);
	if (!lst_a)
		exit_error();
	lst_b = NULL;
	read_exec_stdin(&lst_a, &lst_b);
	free_lst(&lst_a, &lst_b);
	return (0);
}
