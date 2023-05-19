/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:26:47 by dev               #+#    #+#             */
/*   Updated: 2023/05/18 21:06:48 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	cpy_int(int *sorted, t_storage *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		sorted[i] = a->tab[i];
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

int	len_mf(char *mf)
{
	int		i;
	char	**split_mf;

	i = 0;
	split_mf = ft_split(mf, ' ');
	while (split_mf[i])
		i++;
	ft_free_chartable(split_mf);
	return (i);
}

void	hash_array(t_storage *a, int *temp)
{
	int	i;
	int	j;
	int	position;

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

void	algo_choice(t_storage storage_a, int *sorted_array)
{
	if (storage_a.size == 2)
		sort2(storage_a.tab);
	else if (storage_a.size == 3)
		sort3(storage_a.tab);
	else if (storage_a.size == 4)
		sort4(&storage_a);
	else if (storage_a.size == 5)
		sort5(&storage_a);
	else if (storage_a.size <= 101)
		sort_chunk(sorted_array, &storage_a, 5);
	else
		sort_chunk(sorted_array, &storage_a, 11);
}
