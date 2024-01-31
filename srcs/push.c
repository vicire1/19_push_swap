/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:43:52 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/31 16:14:23 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_data *data)
{
	int	i;

	i = data->size_a;
	if (data->size_b > 0)
	{
		while (i > 0)
		{
			data->a[i] = data->a[i - 1];
			i--;
		}
		data->a[0] = data->b[0];
		while (i < data->size_b)
		{
			data->b[i] = data->b[i + 1];
			i++;
		}
		data->size_a++;
		data->size_b--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_data *data)
{
	int	i;

	i = data->size_b;
	if (data->size_a > 0)
	{
		while (i > 0)
		{
			data->b[i] = data->b[i - 1];
			i--;
		}
		data->b[0] = data->a[0];
		while (i < data->size_a)
		{
			data->a[i] = data->a[i + 1];
			i++;
		}
		data->size_b++;
		data->size_a--;
		write(1, "pb\n", 3);
	}
}
