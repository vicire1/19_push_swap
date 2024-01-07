/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:13:25 by vdecleir          #+#    #+#             */
/*   Updated: 2024/01/07 18:54:40 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>           //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_data {
    char        **tab;
    int         nbrs;
    long long   *a;
    long long   *b;
}           t_data;

int         error_message();
int	        freetab(t_data *data, int n);
long long	ft_atol(const char *str);

#endif