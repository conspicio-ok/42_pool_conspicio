/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:27:13 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/27 17:57:07 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numb(char	*nb)
{
	int	i;

	i = 0;
	while (i < 3)
		write(1, &nb[i++], 1);
	if (!(nb[0] == '7' && nb[1] == '8' && nb[2] == '9'))
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	number[3];

	number[0] = '0';
	number[1] = '1';
	number[2] = '2';
	while (number[0] <= '7')
	{
		while (number[1] <= '8')
		{
			while (number[2] <= '9')
			{
				print_numb(number);
				number[2]++;
			}
			number[1]++;
			number[2] = number[1] + 1;
		}
		number[0]++;
		number[1] = number[0] + 1;
		number[2] = number[1] + 1;
	}
}
/*
int	main()
{
	ft_print_comb();
	return (0);
}
*/