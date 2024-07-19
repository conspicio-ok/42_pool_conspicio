/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:46:16 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/27 10:57:15 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	charactere;

	charactere = '`';
	while (charactere++ < 'z')
		write(1, &charactere, 1);
}
/*
int	main(void)
{
	ft_print_alphabet();
	return (0);
}
*/
