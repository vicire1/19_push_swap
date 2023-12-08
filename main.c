/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:14:14 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/08 16:52:12 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_message(void)
{
	write(1, "Error\n", 7);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

static int	one_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '-')
			i++;
		if (ft_isdigit(arg[i]) == 0)
			return (error_message());
		while (ft_isdigit(arg[i]) == 1)
			i++;
		if (arg[i] == ' ')
			i++;
	}
	return (1);
}

static int	arg_checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		if (ft_isdigit(av[i][j]) == 0)
			return (error_message());
		while (ft_isdigit(av[i][j]) == 1)
			j++;
		if (av[i][j] != '\0')
			return (error_message());
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	*a;

	if (ac == 1)
		return (0);
	// else if (ac == 2 && one_arg(av[1]) == 1)
	//     a = put_in_a_1(av[1]);
	else if (ac > 2 && arg_checker(ac, av) == 1)
		a = put_in_a(ac, av);
	return (0);
}
