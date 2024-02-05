/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:13:25 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/05 18:41:20 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h> //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data {
	char	**tab;
	int		nbrs;
	int		*int_tab;
	int		*a;
	int		size_a;
	int		*b;
	int		size_b;
}			t_data;

int			organize_arg(t_data *data, int ac, char **av);
int			error_message(void);
void		freetab(t_data *data, int n, int show_mess);
long long	ft_atol(const char *str);
int			index_in_a(t_data *data, int n);
int			free_array(int *array, int i);
void		sa(t_data *data, int i);
void		sb(t_data *data, int i);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data, int bin);
void		rb(t_data *data, int bin);
void		rr(t_data *data);
void		rra(t_data *data, int bin);
void		rrb(t_data *data, int bin);
void		rrr(t_data *data);
int			find_min_index(int *tab, int size);
int			find_max_index(int *tab, int size);
int			check_order(int *tab, int size);
void		algo3(t_data *data);
void		algo4(t_data *data);
void		algo5(t_data *data);
void		radix(t_data *data);

#endif