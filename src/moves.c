/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwawzyni <dwawzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:23:42 by dwawzyni          #+#    #+#             */
/*   Updated: 2023/02/13 18:52:20 by dwawzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(int *tab,int ac)
{
    int	i;
	int	t;
	int	j;

	i = 0;
	j = tab[i];
	while (i < ac)
	{
		t = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = t;
		i++;
	}
	tab[i] = j;
	write(1,"ra\n",3);
}