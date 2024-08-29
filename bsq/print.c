/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:42:03 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/17 12:57:50 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_print_map(char **map)
{
	while (**map)
	{
		ft_putstr(*map);
		ft_putstr("\n");
		map++;
	}
}
