/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:05:58 by dev               #+#    #+#             */
/*   Updated: 2023/04/06 15:41:15 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_maxb(int len)
{
	int	maxb;
	int	max;

	max = len;
	maxb = 0;
	while (max >> maxb != 0)
		++maxb;
	return (maxb);
}

int	ft_rotate(int *str, int argc)
{
	int	i;
	int	t;
	int	j;

	i = 0;
	while (str[i] == 0)
		i++;
	j = str[i];
	while (i < argc)
	{
		t = str[i];
		str[i] = str[i + 1];
		str[i + 1] = t;
		i++;
	}
	str[i] = j;
	write(1, "ra\n", 3);
	return (1);
}

int	push2(int *strA, int *strB, int argc, char *c)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = argc - 1;
	while (strB[j] != 0)
		j--;
	while (strA[i] == 0)
		i++;
	t = strA[i];
	strA[i] = strB[j];
	strB[j] = t;
	ft_putstr(c);
	return (1);
}
