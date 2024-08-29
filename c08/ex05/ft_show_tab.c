/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserre-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:23:34 by rserre--          #+#    #+#             */
/*   Updated: 2023/08/16 12:19:05 by rserre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ok_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	char	nbr;

	if (nb < 10)
	{
		nbr = nb + '0';
		write(1, &nbr, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ok_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ok_putstr(par[i].copy);
		i++;
	}
}
