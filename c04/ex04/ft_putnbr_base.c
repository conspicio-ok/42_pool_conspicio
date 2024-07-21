/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:58:37 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/04 17:41:16 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	len_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	pos_putnbr_base(unsigned int nb, char *base, unsigned int size_base)
{
	if (nb > size_base - 1)
		pos_putnbr_base(nb / size_base, base, size_base);
	write(1, &base[nb % size_base], 1);
}

int	verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (len_base(base) <= 1)
		return (1);
	while (base[i])
	{
		j = 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		base++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;

	nb = 0;
	if (verif_base(base) == 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
			nb = 2147483648;
		else
			nb = nbr * -1;
	}
	else
		nb = nbr;
	pos_putnbr_base(nb, base, len_base(base));
}
/*
int	main()
{
	ft_putnbr_base(15, "");
	return (0);
}
*/
