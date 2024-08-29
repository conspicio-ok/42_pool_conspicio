/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:40:32 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/17 19:07:05 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	count_words(char *str, char charset)
{
	int	count;

	count = 0;
	while (*str == charset)
		str++;
	while (*str)
	{
		count++;
		while (*str && *str != charset)
			str++;
		while (*str && *str == charset)
			str++;
	}
	return (count);
}

int	len_word(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

char	**ft_split(char *str, char charset)
{
	int		i;
	char	**tab;

	tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!tab)
		return (NULL);
	while (*str == charset)
		str++;
	i = 0;
	while (*str)
	{
		if (len_word(str, charset) == -1)
			return (NULL);
		tab[i] = malloc(sizeof(char) * (len_word(str, charset) + 1));
		if (!tab[i])
			ft_freemap(tab);
		tab[i] = ft_strcpyl(tab[i], str, len_word(str, charset) + 1);
		str += len_word(str, charset);
		while (*str == charset)
			str++;
		i++;
	}
	tab[i] = malloc(sizeof(char));
	tab[i][0] = '\0';
	return (tab);
}
