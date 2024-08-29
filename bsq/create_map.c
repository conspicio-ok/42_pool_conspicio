/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:21:32 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/17 19:35:13 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	len_first_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	verif_first_line(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i] && i < size - 3)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (ERROR);
		i++;
	}
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
			return (ERROR);
		i++;
	}
	if (i != size)
		return (ERROR);
	return (SUCCESS);
}

int	ft_atoi_nb_line(char *str, int size)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < size - 3)
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb);
}

t_map	create_map(char *str)
{
	t_map	map;
	int		len;
	char	*first_line;

	map.map = NULL;
	len = len_first_line(str);
	first_line = malloc(sizeof(char) * (len + 1));
	if (!first_line)
		return (map);
	first_line = ft_strcpyl(first_line, str, len + 1);
	if (verif_first_line(first_line, ft_strlen(first_line)) == 0)
		return (map);
	str += len + 1;
	map.len = ft_atoi_nb_line(first_line, len);
	if (map.len == 0)
		return (map);
	map.map = ft_split(str, '\n');
	map.c_empty = first_line[len - 3];
	map.c_obs = first_line[len - 2];
	map.c_full = first_line[len - 1];
	free(first_line);
	return (map);
}
