/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:49:02 by dev               #+#    #+#             */
/*   Updated: 2023/02/09 15:16:07 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void init(t_storage * storage)
{
    ft_memset(storage,0,sizeof(t_storage));
}

// void decimalToBinary(int num)
// {
    
//    long quotient, remainder;
//     int i, j = 0;
//     char hexadecimalnum[100];
 

 
//     quotient = num;
 
//     while (quotient != 0)
//     {
//         remainder = quotient % 16;
//         if (remainder < 10)
//             hexadecimalnum[j++] = 48 + remainder;
//         else
//             hexadecimalnum[j++] = 55 + remainder;
//         quotient = quotient / 16;
//     }
 
//     // display integer into character
//     for (i = j; i >= 0; i--)
//             printf("%c", hexadecimalnum[i]);
// }