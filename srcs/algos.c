/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:54:24 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/05 13:50:46 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo3(t_data *data)
{
	int	min_index;
	int	max_index;

	min_index = find_min_index(data->a, data->size_a);
	max_index = find_max_index(data->a, data->size_a);
	if (min_index == 1 && max_index == 2)
		sa(data, 0);
	if (min_index == 2 && max_index == 0)
	{
		sa(data, 0);
		rra(data, 0);
	}
	if (min_index == 1 && max_index == 0)
		ra(data, 0);
	if (min_index == 0 && max_index == 1)
	{
		sa(data, 0);
		ra(data, 0);
	}
	if (min_index == 2 && max_index == 1)
		rra(data, 0);
}

void	algo4(t_data *data)
{
	int	min_index;

	min_index = find_min_index(data->a, data->size_a);
	if (min_index == 1 || min_index == 2)
		ra(data, 0);
	if (min_index == 2)
		ra(data, 0);
	if (min_index == 3)
		rra(data, 0);
	if (check_order(data->a, data->size_a) == 0)
	{
		pb(data);
		algo3(data);
		pa(data);
	}
}

void	algo5(t_data *data)
{
	int	min_index;

	min_index = find_min_index(data->a, data->size_a);
	if (min_index == 1 || min_index == 2)
		ra(data, 0);
	if (min_index == 2)
		ra(data, 0);
	if (min_index == 3)
		rra(data, 0);
	if (min_index == 3 || min_index == 4)
		rra(data, 0);
	if (check_order(data->a, data->size_a) == 0)
	{
		pb(data);
		algo4(data);
		pa(data);
	}
}

static void	radix_b(t_data *data, int b_size, int nb_bits, int j)
{
	while (b_size && j <= nb_bits && !check_order(data->b, data->size_b))
	{
		if (((data->b[0] >> j) & 1) == 0)
			rb(data, 0);
		else
			pa(data);
		b_size--;
	}
	if (check_order(data->b, data->size_b))
	{
		while (data->size_b != 0)
			pa(data);
	}
}

void	radix(t_data *data)
{
	int	j;
	int	nb_bits;
	int	size;

	nb_bits = 0;
	size = data->size_a;
	while (size > 1 && ++nb_bits)
		size /= 2;
	j = 0;
	while (j <= nb_bits)
	{
		size = data->size_a;
		while (size && !check_order(data->a, data->size_a))
		{
			if (((data->a[0] >> j) & 1) == 0)
				pb(data);
			else
				ra(data, 0);
			size--;
		}
		radix_b(data, data->size_b, nb_bits, j + 1);
		j++;
	}
	while (data->size_b != 0)
		pa(data);
}
