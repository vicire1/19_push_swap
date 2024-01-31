/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:39:21 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/31 16:12:24 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_index(int *tab, int size)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min = tab[i];
	min_index = 0;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	find_max_index(int *tab, int size)
{
	int	i;
	int	max;
	int	max_index;

	i = 0;
	max = tab[i];
	max_index = 0;
	while (i < size)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	check_order(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
