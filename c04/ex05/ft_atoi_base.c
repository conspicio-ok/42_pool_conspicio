/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:15:04 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/05 09:01:01 by raserre-         ###   ########.fr       */
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

void	skip(char *str, int *neg)
{ // ne change pas l'adresse (faire un return char *)
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*neg *= -1;
		str++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	neg;

	nb = 0;
	neg = 1;
	skip(str, &neg);
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
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi_base("60", "0123456789abcdef"));
	return (0);
}
*/
