/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserre-- <rserre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:57:56 by rserre--          #+#    #+#             */
/*   Updated: 2023/08/21 14:54:55 by rserre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*table;

	i = 0;
	if (min >= max)
		return (0);
	table = malloc((max - min) * sizeof(int));
	if (!table)
		return (0);
	while (min < max)
	{
		table[i] = min;
		i++;
		min++;
	}
	return (table);
}
/*
int main()
{
	int	i;
	int	*table;

	table = ft_range(2, 5);
	i = 0;
	printf("%d\n", ft_range(5, 5));
	while (i++ < 2)
		printf("%d\n", table[i]);
	return (0);
}*/
