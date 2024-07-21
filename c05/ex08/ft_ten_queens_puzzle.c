/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:32:13 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/08 13:48:25 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_nb(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_write_nb(nb + '0');
}

int	calc_queens(unsigned int nb, int tile)
{
	if (tile == 1)
	{
		
}

int	ft_ten_queens_puzzle(void)
{
	calc_queens(0, 1000000000);
	ft_putnbr(15);
	return (1);
}

int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
