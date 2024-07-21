/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:01:48 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/06 18:19:51 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

char	*r_look_line(char **map, int line, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = create_str(size);
	while (i < size)
	{
		str[i] = map[line][i];
		i++;
	}
	return(str);
}

char	*up_look_col(char **map, int col, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = create_str(size);
	while (i < size)
	{
		str[i] = map[i][col];
		i++;
	}
	return(str);
}

char	*l_look_line(char **map, int line, int size)
{
		int     i;
		char    *str;

		i = 0;
		str = create_str(size);
		while (i < size)
		{
				str[i] = map[line][size - i - 1];
				i++;
		}
		return(str);
}

char    *down_look_col(char **map, int col, int size)
{
		int     i;
		char    *str;

		i = 0;
		str = create_str(size);
		while (i < size)
		{
				str[i] = map[size - i - 1][col];
				i++;
		}
		return(str);
}

