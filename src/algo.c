/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:38:29 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/04/06 20:45:13 by dwawzyni         ###   ########.fr       */
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

int	radix_sort(int *str_a, int *str_b, int len)
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
			k = str_a[i];
			if (((k >> i)) & 1)
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
