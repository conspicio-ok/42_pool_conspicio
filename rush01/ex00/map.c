/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:41:48 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/06 12:03:59 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"
#include <stdlib.h>

void	put_zero_map(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			map[i][j] = '0';
			j++;
		}
		map[i][j] = '\0';
		i++;
		j = 0;
	}
	map[i][0] = '\0';
}

char	*create_str(int size)
{
	char	*line;

	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (0);
	return (line);
}

char	**create_map(int size)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * size);
	if (!map)
		return (0);
	while (i < size)
	{
		map[i] = malloc(sizeof(char) * (size + 1));
		if (!map[i])
			return (0);
		i++;
	}
	map[i] = malloc(sizeof(char));
	if (!map[i])
		return (0);
	put_zero_map(map, size);
	return (map);
}

void	free_map(char **map, int size)
{
	int	i;

	i = 0;
	if (!size)
		return ;
	while (i < size - 1)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_str(char *line)
{
	free(line);
}
