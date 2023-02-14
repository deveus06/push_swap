/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:28 by dev               #+#    #+#             */
/*   Updated: 2023/02/13 18:44:42 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_storage
{
    int n;
    int tab[];
}t_storage;


void init(t_storage * storage);
// void decimalToBinary(int num);

void rotate(int *tab,int ac);

#endif