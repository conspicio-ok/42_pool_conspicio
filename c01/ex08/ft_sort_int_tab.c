/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:20:45 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/29 22:15:26 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
		j = i + 1;
	}
}

/*
#include <stdio.h>
int	main()
{
	int tab[6];

	tab[0] = 9;
	tab[1] = 12;
	tab[2] = 18;
	tab[3] = 16;
	tab[4] = 99;
	tab[5] = 98;
	ft_sort_int_tab(tab, 6);
	printf("%d, %d, %d, %d, %d, %d\n", \
	tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	return (0);
}*/
