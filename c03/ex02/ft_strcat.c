/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:37:43 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/01 09:45:28 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char *argv[])
{
    char	str1[50];
    char	str2[50];
    char	ft_str1[50];
    char	ft_str2[50];

	if (argc != 3)
		return (0);
	strcpy(str1, argv[1]);
	strcpy(str2, argv[2]);
	strcpy(ft_str1, argv[1]);
	strcpy(ft_str2, argv[2]);
    printf("%s\n%s\n", strcat(str1, str2), ft_strcat(ft_str1, ft_str2));
	return (0);
}*/