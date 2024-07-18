/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 05:44:10 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/01 17:32:42 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb, char *hex)
{
	char	c;

	c = hex[nb / 16];
	write(1, &c, 1);
	c = hex[nb % 16];
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			write(1, "\\", 1);
			ft_putnbr(str[i], "0123456789abcdef");
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
/*
int	main(void)
{
	char str[22] = "Coucou\n\ntu vas\t bien ?";
	str[4] = 16;
	ft_putstr_non_printable(str);
	return (0);
}
*/