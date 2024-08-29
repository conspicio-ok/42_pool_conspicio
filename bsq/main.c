/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:33:16 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/17 19:56:23 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_bzero(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*fusion;

	len1 = 0;
	len2 = 0;
	fusion = NULL;
	if (s1 != NULL || s2 != NULL)
	{
		if (s1 != NULL)
			len1 = ft_strlen(s1);
		if (s2 != NULL)
			len2 = ft_strlen(s2);
		fusion = malloc((len1 + len2) + 1 * sizeof(char));
		if (fusion == NULL)
			return (NULL);
		ft_bzero(fusion, len1 + len2 + 1);
		if (s1 != NULL)
			ft_strcpyl(fusion, s1, len1 + 1);
		if (s2 != NULL)
			ft_strcpyl(&fusion[len1], s2, len2 + 1);
	}
	free(s1);
	return (fusion);
}

char	*reading(char *dest)
{
	int		rd;
	char	*temp;

	temp = malloc((1024 + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		ft_bzero(temp, 1024 + 1);
		rd = read(0, temp, 1024);
		if (rd < 0)
		{
			if (dest != NULL)
				free(dest);
			free(temp);
			return (NULL);
		}
		dest = ft_strjoin(dest, temp);
		if (dest == NULL)
			break ;
	}
	free(temp);
	return (dest);
}

void	read_with_one(void)
{
	char	*content;
	t_map	map;

	content = NULL;
	content = reading(content);
	if (!content)
	{
		write(2, "map error\n", 11);
		return ;
	}
	map = create_map(content);
	free(content);
	if (!map.map)
		write(2, "map error\n", 11);
	else if (verif_map(map) == 0)
	{
		write(2, "map error\n", 11);
		ft_freemap(map.map);
	}
	else
	{
		ft_put_sqre(map, ft_find_the_sqre(map));
		ft_print_map(map.map);
		ft_freemap(map.map);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		read_with_one();
	else
		ft_call_prog(argc - 1, &argv[1]);
	return (0);
}
