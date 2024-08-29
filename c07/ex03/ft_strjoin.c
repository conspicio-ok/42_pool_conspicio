/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserre-- <rserre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:38:18 by rserre--          #+#    #+#             */
/*   Updated: 2023/08/22 16:43:28 by rserre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	add(char *dest, char *str, int *k)
{
	int	j;

	j = 0;
	while (j < ft_strlen(dest))
		str[(*k)++] = dest[j++];
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		k;
	int		taille;
	char	*str;

	i = 0;
	k = 0;
	taille = ft_strlen(sep) * (size - 1);
	while (i < size)
		taille += ft_strlen(strs[i++]);
	if (size == 0)
		taille = 0;
	i = 0;
	str = malloc((taille + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < size)
	{
		add(strs[i], str, &k);
		if (i < size - 1)
			add(sep, str, &k);
		i++;
	}
	str[k] = '\0';
	return (str);
}
/*
int	main()
{
	char	*strs[4] = {"pomme", "poire", "banane", "tarte au fruit"};
	char	*sep = "";
	char	*res = ft_strjoin(0, strs, sep);

	printf("%s\n", res);
	return (0);
}*/
