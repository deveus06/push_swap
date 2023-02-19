/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:34:57 by dev               #+#    #+#             */
/*   Updated: 2023/02/06 13:08:34 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../push_swap.h"

int count_array(char *array)
{
    t_storage storage;
    char **stack;
    int i;
    
    i = 0;
    stack = ft_split(array,' ');
    while(stack[i] != NULL)
        i++;
    
    storage.n = i;
    return(i);
}

// void return_int_tab(char *array,t_storage storage)
// {
//     int i;
//     char **stack;
//     int tab[count_array(array)];
    
//     i = 1;
//     stack = ft_split(array,' ');
//     while(stack[i] != NULL)
//     {
//         tab[i] = ft_atoi(stack[i]);
//         storage.tab[i] = tab[i];
//         i++;
//     }     
// }

int get_max(char *array)
{
    int max;
    int i;
    char **stack;
   int tab[count_array(array)];
    
    i = 0;
    stack = ft_split(array,' ');
    while(stack[i] != NULL)
    {
        tab[i] = ft_atoi(stack[i]);
        i++;
    }    
    max = tab[0];
    i = 1;
    while(i < count_array(array))
    {
        if(tab[i] > max)
            max = tab[i];
        i++;
    }
    return(max);
}

int main(int ac, char **av)
{
    (void)ac;
    t_storage storage;
    init(storage);
    
    char *array = av[1];
    
    printf("%d",storage.n);
    printf("%d",get_max(array));
}