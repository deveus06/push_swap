/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:23:42 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/05/17 18:57:13 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(int *tab, int ac, char *c)
{
	int	i;
	int	t;
	int	j;

	i = 0;
	j = tab[0];
	while (i < ac - 1)
	{
		t = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = t;
		i++;
	}
	ft_putstr(c);
	tab[i] = j;
	return (1);
}

int	rev_rotate(int *str, int ac, char *c)
{
	int	tmp;
	int	t;
	int	i;

	tmp = str[ac - 1];
	i = ac - 1;
	while (i > 0)
	{
		t = str[i];
		str[i] = str[i - 1];
		str[i - 1] = t;
		i--;
	}
	str[0] = tmp;
	ft_putstr(c);
	return (1);
}

void	ft_switch(int *x, int *y)
{
	int	t;

	t = *x;
	*x = *y;
	*y = t;
}

int	swap(int *str, int ac)
{
	int	i;
	int	t;

	i = ac;
	i = 0;
	t = str[i];
	str[i] = str[i + 1];
	str[i + 1] = t;
	write(1, "sa\n", 3);
	return (1);
}

int	push(t_storage *stack_a, t_storage *stack_b, char *c)
{
	int	i;

	i = stack_b->size;
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = stack_a->tab[0];
	stack_b->size++;
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		++i;
	}
	stack_a->size--;
	ft_putstr(c);
	return (1);
}
