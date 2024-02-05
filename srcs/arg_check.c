/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:10:16 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/05 18:40:53 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	arg_checker(t_data *data, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	data->nbrs = i;
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
	return (0);
}

static int	arg_in_tab(t_data *data, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	data->tab = malloc(sizeof(char *) * ac);
	if (!data->tab)
		return (error_message());
	while (i < ac)
	{
		j = 0;
		data->tab[i - 1] = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		if (!data->tab[i - 1])
			freetab(data, i - 1, 1);
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

static int	double_check(t_data *data, long long temp, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (data->int_tab[j] == temp)
			return (-1);
		j++;
	}
	return (1);
}

static int	tab_in_stack(t_data *data)
{
	int			i;
	long long	temp;

	i = 0;
	data->int_tab = malloc(sizeof(int) * (data->nbrs));
	if (!data->int_tab)
		freetab(data, data->nbrs, 1);
	while (i < data->nbrs)
	{
		temp = ft_atol(data->tab[i]);
		if (double_check(data, temp, i) == -1 || temp > INT32_MAX
			|| temp < INT32_MIN)
		{
			free(data->int_tab);
			freetab(data, data->nbrs, 1);
		}
		data->int_tab[i] = temp;
		i++;
	}
	return (1);
}

int	organize_arg(t_data *data, int ac, char **av)
{
	int	rtn_check;
	int	n;

	n = 0;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		data->tab = ft_split(av[1], ' ');
		if (!data->tab)
			return (error_message());
	}
	else
		arg_in_tab(data, ac, av);
	rtn_check = arg_checker(data, data->tab);
	if (rtn_check == -1)
		freetab(data, data->nbrs, 1);
	tab_in_stack(data);
	if (index_in_a(data, n) == -1)
		freetab(data, data->nbrs, 1);
	freetab(data, data->nbrs, 0);
	free_array(data->int_tab, 0);
	return (1);
}
