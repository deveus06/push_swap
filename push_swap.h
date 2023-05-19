/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:28 by dev               #+#    #+#             */
/*   Updated: 2023/05/18 21:05:07 by dwawzyni         ###   ########.fr       */
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
	int	tab[500];
	int	max;
	int *sorted_tab;
}		t_storage;

void	ft_putstr(char *str);
int		get_max(t_storage *a);
int		smallest(int *str, int c, int len);
int		check_int_range(char *av);
int	ft_is_sorted(int *str, int argc);
void cpy_int(int *sorted, t_storage *a);
int len_mf(char *mf);
int	get_max(t_storage *a);
void	hash_array(t_storage *a, int *temp);
void algo_choice(t_storage storage_a, int *sorted_array);

//moves
int		rotate(int *tab, int ac, char *c);
int		rev_rotate(int *str, int ac, char *c);
int		swap(int *str, int ac);
int		push(t_storage *stack_a, t_storage *stack_b, char *c);

//algos
int		sort3(int str[500]);
int		sort5(t_storage *stack_a);
void sort2(int str[2]);
void sort4(t_storage *stack_a);
void bubble_sort(int *arr, int n);
void	ft_switch(int *x, int *y);
int	sort_chunk(int *sorted_tab, t_storage *a, int woula);
int sort_b(t_storage *a,t_storage *b);

#endif