/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:39:01 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/01 16:37:56 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
int	main(int argc, char *argv[])
{
	char	*ft_dest = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
	char	*dest = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));

	if (argc != 2)
		return (0);
	printf("\n");
	printf("%s : %u\n", ft_dest, ft_strlcpy(ft_dest, argv[1], 5));
	printf("%s : %zu\n", dest, strlcpy(dest, argv[1], 5));
	printf("\n");
	free(ft_dest);
	free(dest);
	return (0);
}
*/