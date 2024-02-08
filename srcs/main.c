/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:14:14 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/08 17:47:28 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dispatch(t_data *data)
{
	if (data->nbrs == 2 && (data->a[0] > data->a[1]))
		sa(data, 0);
	if (data->nbrs == 3)
		algo3(data);
	if (data->nbrs == 4)
		algo4(data);
	if (data->nbrs == 5)
		algo5(data);
	if (data->nbrs > 5)
		radix(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.nbrs = 0;
	if (organize_arg(&data, ac, av) == -1)
		return (-1);
	dispatch(&data);
	free_array(data.a, 0);
	free_array(data.b, 0);
	return (0);
}
