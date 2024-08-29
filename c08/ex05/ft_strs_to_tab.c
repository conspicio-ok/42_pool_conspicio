/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserre-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:05:53 by rserre--          #+#    #+#             */
/*   Updated: 2023/08/16 12:31:32 by rserre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s_table;

	i = 0;
	s_table = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!s_table)
		return (0);
	while (i < ac)
	{
		s_table[i].size = ft_strlen(av[i]);
		s_table[i].str = av[i];
		s_table[i].copy = ft_strdup(s_table[i].str);
		i++;
	}
	s_table[i].str = 0;
	return (s_table);
}

int main()
{
    char *av[4] = {"hello", "green", "lalandhhhhhhhhhhhhhhhhhhh", "catcatcat"};
    t_stock_str *s_structs = ft_strs_to_tab(4, av);
    ft_show_tab(s_structs);

    int i = 0;
    while (i < 4)
    {
        printf("%d\n", s_structs[i].size);
        printf("%s\n", s_structs[i].str);
        printf("%s\n\n", s_structs[i].copy);
        i++;
    }
}
