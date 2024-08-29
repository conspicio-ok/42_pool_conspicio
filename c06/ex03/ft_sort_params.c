/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserre-- <rserre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:11 by rserre--          #+#    #+#             */
/*   Updated: 2023/08/17 17:40:34 by rserre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap_table(char **tab, int nb1, int nb2)
{
	char	*temp;

	temp = tab[nb1];
	tab[nb1] = tab[nb2];
	tab[nb2] = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

void	sort_tab(char **table, int size)
{
	int	i;
	int	search;
	int	little;
	int	diff;

	i = 1;
	little = i + 1;
	search = i + 1;
	while (i < size - 1)
	{
		while (search < size)
		{
			diff = ft_strcmp(table[search], table[little]);
			if (diff < 0)
				little = search;
			search++;
		}
		diff = ft_strcmp(table[i], table[little]);
		if (diff > 0)
			swap_table(table, i, little);
		i++;
		little = i + 1;
		search = i + 1;
	}
}

void	ft_putarg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	sort_tab(argv, argc);
	i = 1;
	while (i < argc)
		ft_putarg(argv[i++]);
}
