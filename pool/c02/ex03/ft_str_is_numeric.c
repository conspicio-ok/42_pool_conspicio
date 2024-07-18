/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:57:58 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/30 21:51:01 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str)
		return (0);
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("pomme:%d\nPOMME:%d\np0mm3:%d\n", ft_str_is_alpha("pomme"), \
		ft_str_is_alpha("POMME"), ft_str_is_alpha("p0mm3"));
	return (0);
}*/
