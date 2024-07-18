/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:59:28 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/27 19:59:31 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numb(char	*nb, int max, int *comma)
{
	int	i;

	i = 0;
	if (*comma > 0)
		write(1, ", ", 2);
	while (i <= max)
	{
		write(1, &nb[i++], 1);
	}
}

void	recursive_print(char *nbr, int position, int max, int *comma)
{
	int	mv;

	while (nbr[position] <= '0' - max + 16 && position < max)
	{
		mv = 0;
		recursive_print(nbr, position + 1, max, comma);
		nbr[position]++;
		while (position + mv <= max)
		{
			nbr[position + mv + 1] = nbr[position + mv] + 1;
			mv++;
		}
	}
	while (position == max && nbr[position] < '9')
	{
		print_numb(nbr, max, comma);
		nbr[position]++;
		(*comma)++;
	}
	if (position == max && nbr[position] == '9')
	{
		print_numb(nbr, max, comma);
		(*comma)++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		comma;
	char	number[10];

	i = 0;
	comma = 0;
	if (0 < n && n < 10)
	{
		while (i < n)
		{
			number[i] = '0' + i;
			i++;
		}
		number[i] = ':';
		recursive_print(number, 0, n - 1, &comma);
	}
}
/*
int	main()
{
	ft_print_combn(2);
	return (0);
}
*/