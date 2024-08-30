/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:22:35 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/14 18:27:25 by raserre-         ###   ########.fr       */
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

int	verif_char(char c, char *base)
{
	while (*base)
	{
		if (*base == c)
			return (1);
		base++;
	}
	return (0);
}

int	verif_base(char *base)
{
	int	j;

	if (len_base(base) <= 1)
		return (1);
	while (*base)
	{
		j = 1;
		while (base[j])
		{
			if (*base == base[j])
				return (1);
			j++;
		}
		if (*base == '+' || *base == '-')
			return (1);
		base++;
	}
	return (0);
}

char	*skip(char *str, int *neg)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*neg *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	neg;

	nb = 0;
	neg = 1;
	str = skip(str, &neg);
	if (verif_base(base) == 1)
		return (0);
	while (*str)
	{
		i = 0;
		while (base[i])
		{
			if (verif_char(*str, base) == 0)
				return (nb * neg);
			if (*str == base[i])
				nb = nb * len_base(base) + i;
			i++;
		}
		str++;
	}
	return (nb * neg);
}

void	pos_putnbr_base(unsigned int nb, char *base, unsigned int size_base)
{
	if (nb > size_base - 1)
		pos_putnbr_base(nb / size_base, base, size_base);
	write(1, &base[nb % size_base], 1);
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
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi_base("     60x0", "0123456789abcdef"));
	return (0);
}
*/

/*
int	main()
{
	ft_putnbr_base(15, "");
	return (0);
}
*/

