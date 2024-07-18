/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:59:31 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/29 19:18:43 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	i;
	int	tab[6];
	i = 0;
	while (i < 6)
	{
		tab[i] = i;
		i++;
	}
	ft_rev_int_tab(tab, 6);
	printf("%d, %d, %d, %d, %d, %d", 
tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	return (0);
}*/
