/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:53:38 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/08 16:38:59 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i])
		i++;
	if (i > 11)
		return (2147483648);
	i = 0;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

int	*put_in_a(int ac, char **av)
{
	int			*a;
	long long	nb;
	int			i;
	int			j;

	a = malloc(sizeof(int *) * (ac - 1));
	if (!a)
		return (0);
	i = 0;
	while (ac > 1)
	{
		j = 0;
		nb = ft_atoi(av[ac - 1]);
		if (nb > INT32_MAX || nb < INT32_MIN)
			return (error_message());
		while (j < i)
		{
			if (a[j] == nb)
				return (error_message());
			j++;
		}
		a[i] = (int)nb;
		i++;
		ac--;
	}
	return (a);
}

// void    put_in_a_1(char *str)
// {
//     int     i;
//     int     j;
//     int     nb;
//     char    *temp;

//     i = 0;
//     while (str[i])
//     {
//         j = 0;
//         while (str[i] && str[i] != ' ')
//         {
//             temp[j] = str[i];
//             i++;
//             j++;
//         }
//         nb = ft_atoi(temp);
//         if (str[i] == ' ')
//             i++;
//     }
// }
