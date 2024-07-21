/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:46:12 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/06 17:46:13 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

int	check_char(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 1;
		while (str[j])
		{
			if (str[i] == str[j] || str[i] == '0')
				return (ERROR);
			j++;
		}
		str++;
	}
	return (SUCCESS);
}

int	count_str(char *str, int size)
{
	int	i;
	int	tmp;
	int	count;

	i = 1;
	tmp = 0;
	count = 1;
	if (check_char(str) == ERROR)
		return (0);
	while (i < size)
	{
		if (str[tmp] < str[i])
		{
			tmp = i;
			count++;
		}
		i++;
	}
	free_str(str);
	return (count);
}

int	check_line(char **map, int line, int size, char *cond)
{
	int		count;
	int		count_rev;
	char	*str_r;
	char	*str_l;

	str_r = r_look_line(map, line, size);
	str_l = l_look_line(map, line, size);
	count = count_str(str_r, size);
	count_rev = count_str(str_l, size);
	if (cond[4 * size + line * 2] == count + '0' 
	&& cond[4 * size + size * 2 + line * 2] == count_rev + '0')
		return (SUCCESS);
	return (ERROR);
}

int	check_col(char **map, int col, int size, char *cond)
{
	int		count;
	int		count_rev;
	char	*str_up;
	char	*str_down;

	str_up = up_look_col(map, col, size);
	str_down = down_look_col(map, col, size);
	count = count_str(str_up, size);
	count_rev = count_str(str_down, size);
	if (cond[col * 2] == count + '0' 
	&& cond[size * 2 + col * 2] == count_rev + '0')
		return (SUCCESS);
	return (ERROR);
}

int	check(char **map, char *num_input, int size)
{
	int	i;
	int	check_count;

	i = 0;
	check_count = 0;
	while (i < size)
	{
		check_count += check_line(map, i, size, num_input);
		check_count += check_col(map, i, size, num_input);
		i++;
	}
	if (check_count == SUCCESS)
		return (SUCCESS);
	return (ERROR);
}
