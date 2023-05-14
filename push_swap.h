/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:28 by dev               #+#    #+#             */
/*   Updated: 2023/04/24 14:45:44 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_storage
{
	int	size;
	int	*tab;
	int	max;
}		t_storage;

void	ft_putstr(char *str);
int		get_max(t_storage *a);
int		smallest(int *str, int c, int len);
void	ft_index(int *str_a, int *str_t, int len);
int		ft_maxb(int len);
int		check_int_range(char *av);
int	ft_is_sorted(int *str, int argc);

//moves
int		rotate(int *tab, int ac, char *c);
int		rev_rotate(int *str, int ac, char *c);
int		swap(int *str, int ac);
int		push(t_storage *stack_a, t_storage *stack_b, char *c);

//for radix
int		push2(int *strA, int *strB, int argc, char *c);
int		ft_rotate(int *str, int argc);

//algos
int		sort3(int *str);
int		sort5(t_storage *stack_a, t_storage *stack_b);
void bubble_sort(int *arr, int n);
void	ft_switch(int *x, int *y);
int	sort_chunk(int *sorted_tab, t_storage *a, int woula);
int sort_b(t_storage *a,t_storage *b);

void	print_stacks(t_storage a, t_storage b);

#endif