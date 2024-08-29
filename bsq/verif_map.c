/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:20:16 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/17 18:52:14 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	verif_char(char *str, char c_empty, char c_obs)
{
	while (*str)
	{
		if (*str != c_empty && *str != c_obs)
			return (0);
		str++;
	}
	return (1);
}

int	how_many_line(char **map)
{
	int	i;

	i = 0;
	while (map[i][0])
		i++;
	return (i);
}

int	verif_map(t_map map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map.map[i]);
	if (how_many_line(map.map) != map.len && how_many_line(map.map) == 0)
		return (ERROR);
	while (map.map[i][0])
	{
		if (verif_char(map.map[i], map.c_empty, map.c_obs) == 0)
			return (ERROR);
		if (len != ft_strlen(map.map[i]) && map.map[i][0] != '\0')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
