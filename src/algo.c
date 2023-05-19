/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:38:29 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/05/18 21:07:57 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort3(int str[500])
{
	int	stack;

	stack = 0;
	if (str[0] > str[1] && str[0] > str[2])
		stack += rotate(str, 3, "ra\n");
	else if (str[1] > str[0] && str[1] > str[2])
		stack += rev_rotate(str, 3, "rra\n");
	if (str[1] < str[0])
		stack += swap(str, 2);
	return (stack);
}

int	sort5(t_storage *stack_a)
{
	int					stack;
	static t_storage	stack_b = {0};
	int					i;

	i = 2;
	stack = 0;
	while (stack_b.size != 2)
	{
		while (stack_a->tab[0] > 1)
		{
			if (i <= stack_a->size / 2)
				stack += rotate(stack_a->tab, stack_a->size, "ra\n");
			else
				stack += rev_rotate(stack_a->tab, stack_a->size, "rra\n");
		}
		stack += push(stack_a, &stack_b, "pb\n");
	}
	stack += sort3(stack_a->tab);
	if (stack_b.tab[0] < stack_b.tab[1])
		rotate(stack_b.tab, stack_b.size, "rb\n");
	stack += push(&stack_b, stack_a, "pa\n");
	stack += push(&stack_b, stack_a, "pa\n");
	return (stack);
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		if (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				ft_switch(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
}

void	sort2(int str[2])
{
	if (str[1] < str[0])
		swap(str, 2);
}

void	sort4(t_storage *stack_a)
{
	static t_storage	b = {0};
	int					j;

	j = smallest(stack_a->tab, 0, stack_a->size);
	while (stack_a->tab[0] != j)
		rotate(stack_a->tab, 4, "ra\n");
	push(stack_a, &b, "pb\n");
	sort3(stack_a->tab);
	push(&b, stack_a, "pa\n");
}
