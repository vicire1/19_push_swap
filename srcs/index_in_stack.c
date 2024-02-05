/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_in_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:29 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/05 18:40:29 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_in_a(t_data *data, int n)
{
	int	i;
	int	place;

	data->a = malloc(sizeof(int) * data->nbrs);
	if (!data->a)
		return (free_array(data->int_tab, 0));
	data->b = malloc(sizeof(int) * data->nbrs);
	if (!data->b)
		return (free_array(data->a, 0), free_array(data->int_tab, 0));
	data->size_a = data->nbrs;
	data->size_b = 0;
	while (n < data->nbrs)
	{
		i = 0;
		place = 1;
		while (i < data->nbrs)
		{
			if (data->int_tab[n] > data->int_tab[i])
				place++;
			i++;
		}
		data->a[n] = place;
		n++;
	}
	return (1);
}
