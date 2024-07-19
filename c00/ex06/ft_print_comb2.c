/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:27:13 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/29 17:27:21 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numb(char	*nb)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 2)
			write(1, " ", 1);
		write(1, &nb[i++], 1);
	}
	if (!(nb[0] == '9' && nb[1] == '8' && nb[2] == '9' && nb[3] == '9'))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	char	number[4];

	number[0] = '0';
	number[1] = '0';
	number[2] = '0' - 1;
	number[3] = '0';
	while (number[0] <= '9')
	{
		while (number[1] <= '9')
		{
			while (number[2]++ < '9')
			{
				while (number[3]++ < '9')
					print_numb(number);
				number[3] = '0' - 1;
			}
			number[1]++;
			number[2] = number[0] - 1;
			number[3] = number[1];
		}
		number[0]++;
		number[1] = '0';
		number[2] = number[0] - 1;
		number[3] = number[1];
	}
}
/*
int	main()
{
	ft_print_comb();
	return (0);
}
*/
