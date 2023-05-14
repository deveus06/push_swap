/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:58 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/05/13 21:06:02 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

void	hash_array(t_storage *a, int *temp)
{
	int		i;
	int		j;
	int		position;

	i = -1;
	while (++i < a->size)
	{
		j = -1;
		position = 0;
		while (++j < a->size)
		{
			if (temp[j] < temp[i] && j != i)
				position += 1;
		}
		a->tab[i] = position;
	}
}

void cpy_int(int *sorted, t_storage *a)
{
	int i = 0;
	while (i < a->size)
	{
		sorted[i] = a->tab[i];
		i++;
	}
	
}

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
		{
			return (1);
		}
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
	int			i;
	int			stack_a[500];
	int			stack_b[500];
	int 		sorted_array[500];
	char		**temp = NULL;
	int			temp_a[500] = {0};
	t_storage	storage_a;
	
	t_storage	storage_b;


	(void)sorted_array;
	ft_memset(stack_a, 0, sizeof(stack_a));
	ft_memset(stack_b, 0, sizeof(stack_a));
	ft_memset(&storage_a, 0, sizeof(storage_a));
	ft_memset(&storage_b, 0, sizeof(storage_b));

	storage_a.tab = stack_a;
	storage_b.tab = stack_b;

	i = -1;

	// ------------- test ---------------------
	// if (ac > 0 && ac <= 500)
	// {
		
	// 	if(ac == 2)
	// 		temp = ft_split(av[1], ' ');
	// 	else
	// 		while(av[++i + 1])
	// 			temp[i] = (av[i + 1]);
	// 	i = -1;
	// 	while(temp[++i])
	// 	{
	// 		if (check_if_letter(temp[i]) || !check_dobles(temp + i)
	// 			|| check_int_range(temp[i]))
	// 			{
	// 				ft_putstr_fd("Error\n",2);
	// 				return(1);
	// 			}
	// 			storage_a.tab[i] = ft_atoi(temp[i]);
	// 		}
	// 	storage_a.size = i;
	// }
	// else 
	// {
	// 	ft_putstr_fd("Error \n",2);
	// 	return(0);
	// }

	//---------- test -------------------
	
	if (ac == 2)
	{
		i = 0;
		temp = ft_split(av[2], ' ');
		while (temp[i])
		{
			temp_a[i] = ft_atoi(temp[i]);
			i++;
		}
	}
	else if (ac > 2)
	{
		while (av[++i + 1])
		{
			if (i >= 500)
			{
				ft_putstr_fd("noob\n", 2);
				return (1);
			}
			if (check_if_letter(av[i + 1]) || !check_dobles(av + i + 1)
				|| check_int_range(av[i + 1]))
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
				temp_a[i] = ft_atoi(av[i + 1]);
		}
	}

	storage_a.size = ac - 1;
	hash_array(&storage_a, temp_a);
	cpy_int(sorted_array, &storage_a);
	bubble_sort(sorted_array, storage_a.size);
	 if (ac == 4)
		sort3(stack_a);
	 else if (ac == 6)
		 sort5(&storage_a, &storage_b);
	else if (ac < 101)
		sort_chunk(sorted_array,&storage_a, 5);
	else
		sort_chunk(sorted_array,&storage_a, 11);
		
	for(int32_t i = 0;i < ac - 1;i++)
	{
		printf("%d\n",  storage_a.tab[i]);
	}
}