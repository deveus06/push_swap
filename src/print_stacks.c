/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:01:24 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/05/18 21:00:17 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		sort_b(t_storage *a, t_storage *b);

void	sort_chunk_segment(t_storage *a, int len, int j, t_storage *b)
{
	int	cpy;
	int	k;

	k = 0;
	cpy = 0;
	while (k < a->size)
	{
		if (a->tab[k] < a->sorted_tab[len * j])
		{
			cpy = a->tab[k];
			if (k < a->size / 2)
				while (a->tab[0] != cpy)
					rotate(a->tab, a->size, "ra\n");
			else
				while (a->tab[0] != cpy)
					rev_rotate(a->tab, a->size, "rra\n");
			push(a, b, "pb\n");
			break ;
		}
		k++;
	}
}

int	sort_chunk(int *sorted_tab, t_storage *a, int woula)
{
	int					i;
	int					j;
	int					len;
	static t_storage	b = {0};

	len = a->size / woula;
	a->sorted_tab = sorted_tab;
	j = 1;
	while (a->size)
	{
		i = 0;
		while (i < len)
		{
			sort_chunk_segment(a, len, j, &b);
			i++;
		}
		j++;
	}
	sort_b(a, &b);
	return (0);
}

int	sort_b(t_storage *a, t_storage *b)
{
	int	i;
	int	cpy;

	cpy = 0;
	while (b->size)
	{
		i = 0;
		while (b->tab[i] != b->size - 1)
			i++;
		cpy = b->tab[i];
		if (i < b->size / 2)
			while (b->tab[0] != cpy)
				rotate(b->tab, b->size, "rb\n");
		else
			while (b->tab[0] != cpy)
				rev_rotate(b->tab, b->size, "rrb\n");
		push(b, a, "pa\n");
	}
	return (0);
}
