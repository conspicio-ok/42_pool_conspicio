/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserre-- <rserre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:32:15 by rserre--          #+#    #+#             */
/*   Updated: 2023/08/21 14:47:38 by rserre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	while (src[i] != '\0')
		i++;
	cpy = malloc((i + 1) * sizeof(char));
	if (!cpy)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*
int	main()
{
	char	src[12] = "Hello World";
	char	*cpy;

	cpy = ft_strdup(src);
	printf("%s\n", cpy);
	return (0);
}*/
