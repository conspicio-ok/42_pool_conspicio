/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:39:49 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/17 19:29:09 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_count_line(char *line, int pos_x, char obs)
{
	int	i;

	i = 0;
	while (line[pos_x + i])
	{
		if (line[pos_x + i] == obs)
			return (i);
		i++;
	}
	return (i);
}

int	ft_count_col(char **map, int pos_x, int pos_y, char obs)
{
	int	i;

	i = 0;
	while (map[pos_y + i][0] && map[pos_y + i][pos_x])
	{
		if (map[pos_y + i][pos_x] == obs)
			return (i);
		i++;
	}
	return (i);
}

void	ft_put_sqre(t_map map, t_sqrt sqre)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < sqre.size)
	{
		j = 0;
		while (j < sqre.size)
		{
			map.map[sqre.y_start + i][sqre.x_start + j] = map.c_full;
			j++;
		}
		i++;
	}
}

t_sqrt	ft_find_sqre(t_map map, int pos_x, int pos_y)
{
	int		size;
	int		error;
	t_sqrt	sqrt;

	size = 0;
	error = 0;
	sqrt.x_start = pos_x;
	sqrt.y_start = pos_y;
	while (error == 0 && map.map[pos_y + size][0])
	{
		if (ft_count_line(map.map[pos_y + size], pos_x, map.c_obs) <= size
			|| ft_count_col(map.map, pos_x + size, pos_y, map.c_obs) <= size)
			error = 1;
		else
			size++;
	}
	sqrt.size = size;
	return (sqrt);
}

t_sqrt	ft_find_the_sqre(t_map map)
{
	int		i;
	int		j;
	t_sqrt	sqrt;
	t_sqrt	tmp_sqrt;

	i = 0;
	sqrt = ft_find_sqre(map, 0, 0);
	while (map.map[i][0])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == map.c_empty && map.map[i][j] != map.c_obs)
			{
				tmp_sqrt = ft_find_sqre(map, j, i);
				if (sqrt.size < tmp_sqrt.size)
					sqrt = tmp_sqrt;
			}
			j++;
		}
		i++;
	}
	return (sqrt);
}
