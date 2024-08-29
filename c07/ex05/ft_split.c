/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserre-- <rserre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:23:59 by rserre--          #+#    #+#             */
/*   Updated: 2023/08/22 16:42:53 by rserre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	is_charset(char letter, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == letter)
			return (1);
		i++;
	}
	return (0);
}

int	pass_cset(char *str, char *charset, int i)
{
	int	count;

	count = 0;
	while (str[i] != '\0' && is_charset(str[i], charset) == 1)
	{
		count++;
		i++;
	}
	return (count);
}

int	pass_char(char *str, char *charset, int i)
{
	int	count;

	count = 0;
	while (str[i] != '\0' && is_charset(str[i], charset) == 0)
	{
		count++;
		i++;
	}
	return (count);
}

void	add_word(char **table, char *str, char *charset)
{
	int	i;
	int	j;
	int	save;
	int	count;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		count = 0;
		i += pass_cset(str, charset, i);
		save = i;
		count += pass_char(str, charset, i);
		table[j] = (char *)malloc((count + 1) * sizeof(char));
		while (count > 0)
		{
			table[j][pass_char(str, charset, save) - count] = str[i];
			count--;
			i++;
		}
		table[j][pass_char(str, charset, save)] = '\0';
		j++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		count;
	char	**words;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		i += pass_cset(str, charset, i);
		if (pass_char(str, charset, i) > 0)
		count++;
		i += pass_char(str, charset, i);
	}
	words = (char **)malloc((count + 1) * sizeof(char *));
	if (!words)
		return (0);
	add_word(words, str, charset);
	return (words);
}
/*
int main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    int i = 0;
    char **mot = ft_split(argv[1], argv[2]);
    while (mot[i])
    {
        printf("%s\n", mot[i]);
        free(mot[i++]);
    }
    free(mot);
    return (0);
}*/
