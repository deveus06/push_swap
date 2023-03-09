/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:49:02 by dev               #+#    #+#             */
/*   Updated: 2023/03/01 10:57:06 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void init(t_storage * storage)
{
    ft_memset(storage,0,sizeof(t_storage));
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

int	smallest(int *str, int c, int len)
{
	int	i;
	int	j;

	i = 1;
	j = str[0];
	while (i < len)
	{
		if (j > str[i])
			j = str[i];
		i++;	
	}
	return (j - c);
}

void	ft_index(int *str_a, int *str_t, int len)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 1;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (str_a[i] > str_a[j])
				index++;
			j++;
		}
		str_t[i] = index;
		index = 1;
		i++;
	}
	i = 0;
	while (i < len)
	{
		str_a[i] = str_t[i];
		i++;
	}
}