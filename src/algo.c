/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:38:29 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/05/17 20:23:28 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	sort3(int str[500])
{
	int	stack;

	stack = 0;
	if (str[0] > str[1] && str[0] > str[2])
		stack += rotate(str, 3, "ra\n");
	else if (str[1] > str[0] && str[1] > str[2])
		stack += rev_rotate(str, 3, "rra\n");
	if(str[1]<str[0])
		stack += swap(str, 2);
	return (stack);
}

int	sort5(t_storage *stack_a)
{
	int	small;
	int	stack;
	t_storage stack_b = {0};
	
	int i = 2;
	stack = 0;
	while (stack_b.size != 2)
	{
		small = smallest(stack_a->tab, 0, stack_a->size);
		while (stack_a->tab[0] != small)
		{
			if(i <= stack_a->size / 2)
				stack += rotate(stack_a->tab, stack_a->size, "ra\n");
			else 
				stack += rev_rotate(stack_a->tab,stack_a->size,"rra\n");
		}
		stack += push(stack_a, &stack_b, "pb\n");
	}
	stack += sort3(stack_a->tab);
	stack += push(&stack_b, stack_a, "pa\n");
	stack += push(&stack_b, stack_a, "pa\n");
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

void sort2(int str[2])
{
	if(str[1]<str[0])
		swap(str,2);
}

void sort4(t_storage *stack_a)
{
	t_storage b = {0};
	int j;
	
	j = smallest(stack_a->tab,0,stack_a->size);
	while(stack_a->tab[0] != j)
		rotate(stack_a->tab,4,"ra\n");
	push(stack_a,&b,"pb\n");
	sort3(stack_a->tab);
	push(&b,stack_a,"pa\n");
}