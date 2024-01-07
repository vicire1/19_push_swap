/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:14:14 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/07 18:59:32 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	arg_checker(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		if (ft_isdigit(tab[i][j]) == 0)
			return (-1);
		while (ft_isdigit(tab[i][j]) == 1)
			j++;
		if (tab[i][j] != '\0')
			return (-1);
		i++;
	}
	return (i);
}

static int	arg_in_tab(t_data *data, int ac, char **av)
{
	int 	i;
	int		j;

	i = 1;
	data->tab = malloc(sizeof(char *) * ac);
	if (!data->tab)
		return (-1);
	while (i < ac)
	{
		j = 0;
		data->tab[i - 1] = malloc(sizeof(char) * ft_strlen(av[i]));
		if (!data->tab[i - 1])
			return (freetab(data, i - 1));
		while (av[i][j])
		{
			data->tab[i - 1][j] = av[i][j];
			j++;
		}
		data->tab[i - 1][j] = '\0';
		i++;
	}
	data->tab[ac - 1] = NULL;
	return (1);
}

static int	double_check(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (data->a[j] == data->a[i])
			return (-1);
		j++;
	}
	return (1);
}

static int	stack_in_a(t_data *data)
{
	int	i;

	i = 0;
	data->a = malloc(sizeof(int) * (data->nbrs - 1));
	if (!data->a)
		return (freetab(data, data->nbrs));
	while (i < data->nbrs)
	{
		data->a[i] = ft_atol(data->tab[data->nbrs - 1 - i]);
		if (double_check(data, i) == -1 || data->a[i] < INT32_MIN || data->a[i] > INT32_MAX)
		{
			free(data->a);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int	i = 0;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	    data.tab = ft_split(av[1], ' ');
	else
		arg_in_tab(&data, ac, av);
	if (!data.tab)
		return (error_message());
	data.nbrs = arg_checker(data.tab);
	if (data.nbrs == -1)
		return (freetab(&data, data.nbrs), error_message());
	if (stack_in_a(&data) == -1)
		return (freetab(&data, data.nbrs), error_message());
	while (i < data.nbrs)
	{
		printf("%lli\n", data.a[i]);
		i++;
	}
	return (0);
}
