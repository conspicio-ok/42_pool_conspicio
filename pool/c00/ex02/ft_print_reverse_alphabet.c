/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:46:16 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/29 17:26:14 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	charactere;

	charactere = '{';
	while (charactere-- > 'a')
		write(1, &charactere, 1);
}
/*
int	main(void)
{
	ft_print_alphabet();
	return (0);
}
*/
