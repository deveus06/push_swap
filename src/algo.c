/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student->42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:20:21 by dev               #+#    #+#             */
/*   Updated: 2023/03/08 17:47:21 by dev              ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int sort3(int *str)
{
    int	stack;

	stack = 0;
	if (str[0] > str[1] && str[0] > str[2])
		stack += rotate(str, 3, "ra\n");
	else if (str[1] > str[0] && str[1] > str[2])
		stack += rev_rotate(str, 3, "rra\n");
    stack += swap(str, 2);

	return (stack);
}

//bubble sort 
int sort5(t_storage * stack_a, t_storage * stack_b)
{
	int small;
	int stack;
	
	stack = 0;
	while (stack_b->size != 2)
	{
		small = smallest(stack_a->tab, 0, stack_a->size);
		while (stack_a->tab[0] != small )
		{
			//printf("Tab : %d Small : %d size : %d\n", stack_a->tab[stack_a->size - 1], small, stack_a->size);
			stack += rotate(stack_a->tab, stack_a->size, "ra\n");
		}
		stack += push(stack_a, stack_b, "pb\n");
	}
	stack += sort3(stack_a->tab);
		
		stack += push(stack_b, stack_a, "pa\n");
		stack += push(stack_b, stack_a, "pa\n");

	//stack += rev_rotate(stack_a->tab, stack_a->size, "rra\n");
	//stack += rev_rotate(stack_a->tab, stack_a->size, "rra\n");
		
	return (stack);
}

int	radix_sort(int * str_a, int * str_b,int len)
{
	int	i;
	int	j;
	int	k;
	int	max;
	int	u;

	i = -1;
	j = 0;
	u = 0;
	max = ft_maxb(len);
	while (++i < max)
	{
		while (j++ < len)
		{
			k = ft_findn(str_a);
			if (((k >> i))&1)
				u += ft_rotate(str_a, len - 1);
			else
				u += push2(str_a, str_b, len, "pb\n");
		}
		j = 0;
		while (str_b[len - 1] != 0)
			u += push2(str_b, str_a, len, "pa\n");
	}
	return (u);
}