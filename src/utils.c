/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:49:02 by dev               #+#    #+#             */
/*   Updated: 2023/04/05 15:33:59 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

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

int	check_int_range(char *av)
{
	int		t;
	char	*r;

	t = ft_atoi(av);
	r = ft_itoa(t);
	if (ft_strncmp(av, r, 1024))
	{
		free(r);
		return (1);
	}
	free(r);
	return (0);
}

int	ft_is_sorted(int *str, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (str[i] > str[i + 1])
		{
			printf("%d < %d\n", str[i], str[i + 1]);
			return (0);
		}
		i++;
	}
	return (1);
}