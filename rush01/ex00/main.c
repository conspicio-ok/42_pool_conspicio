/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:55:35 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/06 10:19:39 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

int main(int argc, char **argv)
{
	int	len;

	len = 0;
	if (argc == 2)
		len = verif_number(argv[1]);
	if (argc != 2 || len == ERROR)
	{
		ft_putstr("please enter correct format : ");
		ft_putstr("./rush-01 colXup colXdown rowXleft rowXright\n");
		ft_putstr("with X into 3 and 9");
		return (SUCCESS);
	}
	if (rush01(len, argv[1]) == ERROR)
		ft_putstr("\n");
	return (SUCCESS);
}
