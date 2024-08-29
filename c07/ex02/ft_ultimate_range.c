/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserre-- <rserre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:57:56 by rserre--          #+#    #+#             */
/*   Updated: 2023/08/22 16:44:27 by rserre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	len = max - min;
	*range = malloc(sizeof(int) * len);
	if (!*range)
		return (-1);
	while (min < max)
		(*range)[i++] = min++;
	return (len);
}
/*
int main()
{
	int *range;
	printf("%d\n", ft_ultimate_range(&range, 5, 10));
}
*/