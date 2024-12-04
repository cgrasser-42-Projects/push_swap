/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:31:12 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/01 16:11:03 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_str_isdigit(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	if (*str == '-' || *str == '+')
	{
		if (size <= 1)
			return (0);
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

char	**ft_parse(int argc, char *argv[])
{
	char	**values;
	int		i;

	if (argc == 2)
		values = ft_split(argv[1], 32);
	else if (argc > 2)
	{
		argv++;
		values = argv;
	}
	else
		return (NULL);
	i = 0;
	while (values[i])
	{
		if (!ft_str_isdigit(values[i]))
			return (NULL);
		i++;
	}
	return (values);
}