/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:43:46 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/31 16:13:24 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_data *data, int bin)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->a[0];
	while (i < data->size_a - 1)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->a[data->size_a - 1] = temp;
	if (bin == 0)
		write(1, "ra\n", 3);
}

void	rb(t_data *data, int bin)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->b[0];
	while (i < data->size_b - 1)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->b[data->size_b - 1] = temp;
	if (bin == 0)
		write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	ra(data, 1);
	rb(data, 1);
	write(1, "rr\n", 3);
}
