/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:55:06 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/09 15:57:23 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int error_message()
{
    write(1, "Error\n", 7);
    exit (0);
}

void	freetab(t_data *data, int n, int show_mess)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(data->tab[i]);
		data->tab[i] = NULL;
		i++;
	}
	free(data->tab);
	data->tab = NULL;
	if (show_mess == 1)
		error_message();
}

long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb * sign > 2147483647 || nb * sign < -2147483648)
			return (2147483648);
		i++;
	}
	return (nb * sign);
}

int	free_array(int *array)
{
	free(array);
	array = NULL;
	exit (0);
}