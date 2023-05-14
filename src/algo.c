/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:38:29 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/04/24 14:48:34 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	sort3(int *str)
{
	int	stack;

	stack = 0;
	if (str[0] > str[1] && str[0] > str[2])
		stack += rotate(str, 3, "ra\n");
	else if (str[1] > str[0] && str[1] > str[2])
		stack += rev_rotate(str, 3, "rra\n");
	if(str[1]< str[0])
		stack += swap(str, 2);
	return (stack);
}

int	sort5(t_storage *stack_a, t_storage *stack_b)
{
	int	small;
	int	stack;

	stack = 0;
	while (stack_b->size != 2)
	{
		small = smallest(stack_a->tab, 0, stack_a->size);
		while (stack_a->tab[0] != small)
			stack += rotate(stack_a->tab, stack_a->size, "ra\n");
		stack += push(stack_a, stack_b, "pb\n");
	}
	stack += sort3(stack_a->tab);
	stack += push(stack_b, stack_a, "pa\n");
	stack += push(stack_b, stack_a, "pa\n");
	return (stack);
}

void bubble_sort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                ft_switch(&arr[j], &arr[j + 1]);
            }
        }
    }
}
