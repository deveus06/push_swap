#include "../push_swap.h"


int sort_b(t_storage *a,t_storage *b);
// DEBUG function to print contents of stacks
void	print_stacks(t_storage a, t_storage b)
{
	usleep(200000);
	printf("\e[1;1H\e[2J");
	printf("  A | B  \n");
	printf("---------\n");
	for (int i = 0; i < 25; ++i)
	{
		if (i < a.size)
			printf(" %2i |", a.tab[i]);
		else
			printf("  - |");
		if (i < b.size)
			printf(" %-2i \n", b.tab[i]);
		else
			printf(" -  \n");
	}
	return ;
}

int	sort_chunk(int *sorted_tab, t_storage *a, int woula)
{
	int max_nb_in_chunk;
	int i;
	int j;
	int k = 0;
	int len = a->size / woula;
	int cpy = 0;
	t_storage b = { 0 };
	
	j = 1;

	while (a->size)
	{
		i = 0;
		max_nb_in_chunk = sorted_tab[len * j];
		while (i <  len)
		{
			k  = 0;
			while(k < a->size)
			{
				if(a->tab[k] < max_nb_in_chunk)
					{
						cpy = a->tab[k];
						if(k < a->size/2)
							while(a->tab[0] != cpy)
								rotate(a->tab,a->size,"ra\n");
						else
							while(a->tab[0] != cpy)
								rev_rotate(a->tab,a->size,"rra\n");
						push(a, &b, "pb\n");
						break;
					}
				k++;
			}
			i++;
		}
		j++;
	}
	sort_b(a, &b);
	return (0);
}

int sort_b(t_storage *a,t_storage *b)
{
	int i;
	int cpy = 0;

	while (b->size)
	{
		i = 0;
		while(b->tab[i] != b->size - 1)
		{
			printf("----%d\n",b->tab[i]);
		 	i++;
		}
		cpy = b->tab[i];
		if(i < b->size / 2)
			while(b->tab[0] != cpy)
				rotate(b->tab,b->size,"rb\n");
		else
			while(b->tab[0] != cpy)
				rev_rotate(b->tab,b->size,"rrb\n");
		push(b, a, "pa\n");
	}
	return(0);
}