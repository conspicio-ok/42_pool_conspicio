/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:23:43 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/29 11:23:45 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char letter)
{
	write(1, &letter, 1);
}

void	print_line(int len, char start, char middle, char end)
{
	int	i;

	i = 0;
	ft_putchar(start);
	while (i < len - 2)
	{
		ft_putchar(middle);
		i++;
	}
	if (len > 1)
		ft_putchar(end);
	ft_putchar('\n');
}
