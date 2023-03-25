/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:34:57 by dev               #+#    #+#             */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void printstack(t_storage * stack)
{
    int i = 0;

    while (i < stack->size)
    {
        printf("%d\n", stack->tab[i]);
        i++;
    }
}

int get_max(t_storage * a)
{
    int i;
    int max;

    max = 0;
    i = 0;
    while (i < a->size)
    {
        if (a->tab[i] > max)
            max = a->tab[i];
        i++;
    }
    a->max = max;
    return(max);

}

int main(int ac, char **av)
{
    (void)ac;
    int i;
    //char **temp;
    t_storage storage_a;
    t_storage storage_b;


    int stack_a[500];
    int stack_b[500];
   // int stack_t[500];


    ft_memset(stack_a, 0, sizeof(stack_a));
    ft_memset(&storage_a, 0, sizeof(storage_a));
    ft_memset(&storage_b, 0, sizeof(storage_b));
    storage_a.tab = stack_a;
    storage_b.tab = stack_b;

    
    i = -1;
    // if (ac == 2)
    // {
    //     temp = ft_split(av[1],' ');
    //     while (temp[++i])
    //     {
    //         stack_a[i] = ft_atoi(temp[i]);
    //         stack_b[i] = 0;
    //         stack_t[i] = stack_a[i];
    //     }
    //     storage_a.size = i;
    // }
    // else
    // {
        while (av[++i + 1])
        {
            storage_a.tab[i] = ft_atoi(av[i + 1]);
        }
        storage_a.size = ac - 1;
    // }
    get_max(&storage_a);
	radix_sort(storage_a.tab, storage_b.tab, i);

}