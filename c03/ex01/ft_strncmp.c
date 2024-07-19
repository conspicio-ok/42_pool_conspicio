/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:23:20 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/01 09:35:44 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	printf("%d\n", ft_strncmp(argv[1], argv[2], 0));
	printf("%d\n", strncmp(argv[1], argv[2], 0));
	return (0);
}
*/