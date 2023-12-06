/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:14:14 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/06 18:18:36 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

static int one_arg(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (ft_isdigit(arg[i]) == 0)
        {
            write(1, "Error\n", 7);
            return (0);
        }
        while (ft_isdigit(arg[i]) == 1)
            i++;
        if (arg[i] == ' ')
            i++;
    }
    return (1);
}

static int arg_checker(int ac, char **av)
{
    
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (0);
    else if (ac == 2)
        one_arg(av[1]);
    else if (ac > 2)
        arg_checker(ac, av);
    return (0);
}
