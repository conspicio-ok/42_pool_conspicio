/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:46:04 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/04 20:13:45 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;

	fact = 1;
	if (nb < 1)
		return (0);
	if (nb == 1)
		return (1);
	while (nb >= 1)
	{
		fact *= nb;
		nb--;
	}
	return (fact);
}
