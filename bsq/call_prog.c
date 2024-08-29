/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:36 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/17 19:46:34 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i][0])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	ft_call_prog(int len, char **maps)
{
	int		i;
	char	*content;
	t_map	map;

	i = 0;
	while (i < len)
	{
		content = readtab(maps[i]);
		if (!content)
			return ;
		map = create_map(content);
		free(content);
		if (!map.map || verif_map(map) == ERROR)
			write(2, "map error\n", 11);
		else
		{
			ft_put_sqre(map, ft_find_the_sqre(map));
			ft_print_map(map.map);
		}
		if (map.map)
			ft_freemap(map.map);
		i++;
		if (i < len)
			write(1, "\n", 1);
	}
}
