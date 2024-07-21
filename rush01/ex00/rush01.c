/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:41:14 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/06 11:41:28 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

void	brut_line(char **map, int size, char *num_input, int x, int y)
{
	if (check_line(map, y, size, num_input) == SUCCESS)
		return ;
	if (map[y][0] == '5')
		return ;
	if (x > 0 && map[y][x] >= size + '0')
	{
		map[y][x] = '1';
		map[y][x - 1]++;
		brut_line(map, size, num_input, x - 1, y);
	}
	else if (map[y][x + 1])
		brut_line(map, size, num_input, x + 1, y);
	else if (x == size - 1 && map[y][x] != size + '0')
	{
		map[y][x]++;
		brut_line(map, size, num_input, x, y);
	}
}

void	brut(char **map, int size, int y, char *num_input)
{
	if (check(map, num_input, size) == SUCCESS || map[0][0] == '5')
		return ;
	if (map[y + 1][0] == '5' && y < size - 1)
	{
		map[y + 1][0] = '1';
		map[y][size - 1]++;
	}
	else if (map[y + 1][0])
	{
		brut_line(map, size, num_input, 0, y);
		brut(map, size, y + 1, num_input);
		if (check(map, num_input, size) == ERROR && map[y][size - 1] != size + '1')
		{
			map[size - 1][size - 1]++;
			brut(map, size, y + 1, num_input);
		}
	}
	else if (y == size - 1 && map[y][0] != size + '1')
	{
		brut_line(map, size, num_input, 0, y);
		if (map[y][0] == '5')
			brut(map, size, y - 1, num_input);
	}
}

int rush01(int size, char *num_input)
{
	char    **map;

	map = create_map(size);
	if (!map)
		return (ERROR);
	brut(map, size, 0, num_input);
	print_map(map, size);
	free_map(map, size);
	return (SUCCESS);
}
