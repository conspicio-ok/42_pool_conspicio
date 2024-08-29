/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:31:58 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/17 18:19:49 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcpyl(char *dest, char *src, int size)
{
	int		i;

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
	return (dest);
}

int	count_line_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	while (str[i] && str[i] != '\n')
	{
		len++;
		i++;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
