/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:23:42 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/03/30 08:38:53 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(int *tab, int ac, char *c)
{
	int	i;
	int	t;
	int	j;

	i = 0;
	j = tab[i];
	while (tab[i] == 0)
		i++;
	while (i < ac - 1)
	{
		t = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = t;
		i++;
	}
	printf("%s", c);
	tab[i] = j;
	return (1);
}

int	rev_rotate(int *str, int ac, char *c)
{
	int	tmp;

	tmp = str[ac - 1];
	for (int i = ac - 1; i > 0; i--)
	{
		str[i] = str[i - 1];
	}
	str[0] = tmp;
	printf("%s", c);
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
	if (str[i] && str[i + 1] && str[i] > str[i + 1])
	{
		t = str[i];
		str[i] = str[i + 1];
		str[i + 1] = t;
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

int	push(t_storage *stack_a, t_storage *stack_b, char *c)
{
	int	tmp;
	int	i;

	tmp = stack_b->tab[stack_b->size - 1];
	for (int i = stack_b->size; i > 0; i--)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
	}
	stack_b->tab[0] = stack_a->tab[0];
	stack_b->size++;
	i = 0;
	while (i < stack_a->size - 1)
	{
		tmp = stack_a->tab[i];
		stack_a->tab[i] = stack_a->tab[i + 1];
		stack_a->tab[i + 1] = tmp;
		i++;
	}
	stack_a->size--;
	printf("%s", c);
	return (1);
}