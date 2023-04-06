/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:34:57 by dev               #+#    #+#             */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

int	check_dobles(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_strncmp(str[0], str[i], 1024))
			return (0);
		i++;
	}
	return (1);
}

int	check_if_letter(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[0] == '-' && str[1])
			continue ;
		else if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

void	printstack(t_storage *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		printf("%d\n", stack->tab[i]);
		i++;
	}
}

int	get_max(t_storage *a)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->tab[i] > max)
			max = a->tab[i];
		i++;
	}
	a->max = max;
	return (max);
}

int	main(int ac, char **av)
{
	int i;
	t_storage storage_a;
	t_storage storage_b;

	int stack_a[500];
	int stack_b[500];
	char **temp;

	ft_memset(stack_a, 0, sizeof(stack_a));
	ft_memset(&storage_a, 0, sizeof(storage_a));
	ft_memset(&storage_b, 0, sizeof(storage_b));
	storage_a.tab = stack_a;
	storage_b.tab = stack_b;

	i = -1;
	if (ac == 2)
	{
		i = 0;
		temp = ft_split(av[1],' ');
		while(temp[i])
		{
			storage_a.tab[i] = ft_atoi(temp[i]);
			i++;
		}
	}
	else if(ac > 2)
	{
		while (av[++i + 1])
		{
			if (check_if_letter(av[i + 1]) || !check_dobles(av + i + 1)
				|| check_int_range(av[i + 1]))
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			storage_a.tab[i] = ft_atoi(av[i + 1]);
		}
		i = ac - 1;
	}
	if(ft_is_sorted(storage_a.tab, i))
		return(0);
	storage_a.size = ac - 1;
	get_max(&storage_a);

	if (ac == 1 || ac > 500)
		return (0);
	else if (ac == 4)
		sort3(stack_a);
	else if (ac == 6)
		sort5(&storage_a, &storage_b);
	else
		radix_sort(storage_a.tab, storage_b.tab, i);
}