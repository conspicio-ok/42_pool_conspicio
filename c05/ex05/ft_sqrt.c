/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:11:11 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/08 12:34:40 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 2;
	if (nb < 3)
		return (0);
	while (i <= nb / 2 && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("2:%d\n", ft_sqrt(2));
	printf("4:%d\n", ft_sqrt(4));
	printf("5:%d\n", ft_sqrt(5));
	printf("81:%d\n", ft_sqrt(81));
	return (0);
}
*/
