/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:14:55 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/04 20:24:11 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nb_pow;

	int_pow = 1;
	if (power < 0i || (power == 0 && nb == 0))
		return (0);
	if (power == 0)
		return (1);
	while (power >= 1)
	{
		nb_power *= nb;
		power--;
	}
	return (nb_power);
}
