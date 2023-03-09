/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:28 by dev               #+#    #+#             */
/*   Updated: 2023/03/09 15:09:01 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_storage
{
    int size;
    int * tab;
    int max;
}t_storage;



void	ft_putstr(char *str);
int count_array(char *array);
int get_max(t_storage * a);
int	smallest(int *str, int c, int len);
void	ft_index(int *str_a, int *str_t, int len);
int	ft_findn(int *str);
int	ft_maxb(int len);

//moves
int    rotate(int *tab,int ac, char *c);
int	rev_rotate(int *str, int ac, char *c);
int	swap(int *str, int ac);
int	push(t_storage * stack_a, t_storage * stack_b, char *c);

//pour radix
int	push2(int *strA, int *strB, int argc, char *c);
int	ft_rotate(int *str, int argc);

//algos
int sort3(int *str);
int sort5(t_storage * stack_a, t_storage * stack_b);
int	radix_sort(int * str_a, int * str_b,int len);

void printstack(t_storage * stack);
#endif