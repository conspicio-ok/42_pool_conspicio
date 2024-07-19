/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:50:53 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/01 13:47:45 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(*to_find))
		return (str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && to_find[j])
			j++;
		if (!(to_find[j]))
			return (&str[i]);
		j = 0;
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	printf(":%s:\n", strstr(argv[1], argv[2]));
	printf(":%s:\n", ft_strstr(argv[1], argv[2]));
	return (0);
}*/
