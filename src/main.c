/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:58 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/05/17 17:12:20 by dev              ###   ########.fr       */
/*                                                                            */
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
			return (1);
	}
	return (0);
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

int	main(int ac, char **av)
{
	static int 			sorted_array[500] = {0};
	static int			temp_a[500] = {0};
	t_storage			storage_a;	
	
	if (ac < 2)
		return(0);

	ft_memset(&storage_a, 0, sizeof(storage_a));
	
	if (check_error(av, ac, temp_a))
		return (0);

	storage_a.size = (ac > 2) ? ac - 1 : len_mf(av[1]);
	


	hash_array(&storage_a, temp_a);
		
	cpy_int(sorted_array, &storage_a);
	bubble_sort(sorted_array, storage_a.size);
	

	
	if(ft_is_sorted(storage_a.tab,storage_a.size))
		return(1);	

	if(storage_a.size == 2)
		sort2(storage_a.tab);
	else if (storage_a.size == 3)
		sort3(storage_a.tab);
	else if (storage_a.size == 4)
		sort4(&storage_a);
	else if (storage_a.size == 5)
		 sort5(&storage_a);
	else if (storage_a.size <= 101)
		sort_chunk(sorted_array,&storage_a, 5);
	else
		sort_chunk(sorted_array,&storage_a, 11);
}