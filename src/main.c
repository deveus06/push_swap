/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:58 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/05/13 22:21:26 by dev              ###   ########.fr       */
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
		{
			return (0);
		}
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
			printf("%s\n", str);

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


int check_error2(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (check_if_letter(str[i]) || !check_dobles(str + i)
			|| check_int_range(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int check_error(char **av, int ac, int temp_a[500])
{
	char **temp;
	int i;
	
	i = 0;
	if (ac == 2)
	{
		temp = ft_split(av[1], ' ');
		while (temp[i])
		{
			temp_a[i] = ft_atoi(temp[i]);
			i++;
		}

		// free temp ici 
		return(check_error2(temp));
	}
	else
	{
		while (av[i + 1])
		{
			temp_a[i] = ft_atoi(av[i + 1]);
			i++;
		}	
		return(check_error2(av + 1));
	}
}

int len_mf(char *mf)
{
	int i = 0;
	int count = 1;

	while (mf[i])
	{
		if (mf[i] == ' ')
			count++;
		i++;
	}
	return (count);	
}

int	main(int ac, char **av)
{
	static int 			sorted_array[500] = {0};
	static int			temp_a[500] = {0};
	t_storage			storage_a;	

	ft_memset(&storage_a, 0, sizeof(storage_a));
	
	if (check_error(av, ac, temp_a))
		return (0);

	storage_a.size = (ac > 2) ? ac - 1 : len_mf(av[1]);
	hash_array(&storage_a, temp_a);
	cpy_int(sorted_array, &storage_a);
	bubble_sort(sorted_array, storage_a.size);
	 if (ac == 4)
		sort3(storage_a.tab);
	 else if (ac == 6)
		 sort5(&storage_a);
	else if (ac <= 101)
		sort_chunk(sorted_array,&storage_a, 5);
	else
		sort_chunk(sorted_array,&storage_a, 11);
		for(int i = 0; i < storage_a.size; i++)
			printf("%d\n", storage_a.tab[i]);
}