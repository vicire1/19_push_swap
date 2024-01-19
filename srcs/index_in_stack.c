/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_in_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:29 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/15 14:48:02 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int index_in_a(t_data *data)
{
    int i;
    int n;
    int place;

    n = 0;
    data->a = malloc(sizeof(int) * data->nbrs);
    data->b = malloc(sizeof(int) * data->nbrs);
    if (!data->a || !data->b)
        free_array(data->int_tab);
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
