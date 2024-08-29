/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:45:11 by gfontagn          #+#    #+#             */
/*   Updated: 2024/07/16 18:14:02 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	count_file_size(char *map_name)
{
	ssize_t		read_sz;
	ssize_t		file_sz;
	int			fd;
	char		buffer[4096];

	file_sz = 0;
	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		return (0);
	read_sz = read(fd, buffer, 4096);
	while (read_sz > 0)
	{
		file_sz += read_sz;
		read_sz = read(fd, buffer, 4096);
	}
	close(fd);
	return (file_sz);
}

char	*readtab(char *map_name)
{
	int		fd;
	int		rd;
	char	*content;
	int		file_sz;

	file_sz = count_file_size(map_name);
	if (!file_sz)
		return (NULL);
	content = malloc((file_sz + 1) * sizeof(char));
	if (!content)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	rd = read(fd, content, file_sz);
	return (content);
}
