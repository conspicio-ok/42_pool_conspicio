/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:37:43 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/01 16:01:43 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_d;
	unsigned int	len_s;

	i = 0;
	j = 0;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (size <= len_d)
		return (size + len_s);
	if (size <= len_s && len_d > size)
		return (size + len_d);
	while (dest[i])
		i++;
	while (src[j] && i + j < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (len_d + len_s);
}
/*
#include <stdio.h>
#include <bsd/string.h>
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
    printf("%s:%s:%zu\n", str1, str2, strlcat(str1, str2, 6));
	printf("%s:%s:%u\n", ft_str1, ft_str2, ft_strlcat(ft_str1, ft_str2, 6));
	return (0);
}
*/