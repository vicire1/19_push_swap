/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:14:14 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/07 19:15:05 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	
	if (organize_arg(&data, ac, av) == -1)
		return (-1);
	return (0);
}
