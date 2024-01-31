/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:43:49 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/31 16:13:21 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_data *data, int bin)
{
	int	i;
	int	temp;

	i = data->size_a - 1;
	temp = data->a[i];
	while (i > 0)
	{
		data->a[i] = data->a[i - 1];
		i--;
	}
	data->a[0] = temp;
	if (bin == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data, int bin)
{
	int	i;
	int	temp;

	i = data->size_b - 1;
	temp = data->b[i];
	while (i > 0)
	{
		data->b[i] = data->b[i - 1];
		i--;
	}
	data->b[0] = temp;
	if (bin == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	rra(data, 1);
	rrb(data, 1);
	write(1, "rrr\n", 4);
}
