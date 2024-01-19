/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:14:14 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/17 16:59:08 by vdecleir         ###   ########.fr       */
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
	
	if (data->nbrs == 5)

	if (data->nbrs > 5)
	
}

int	main(int ac, char **av)
{
	t_data	data;
	
	organize_arg(&data, ac, av);
	dispatch(&data);
	free_array(data.a);
	free_array(data.b);
	return (0);
}
