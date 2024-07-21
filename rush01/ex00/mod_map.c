/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:22:30 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/06 13:22:32 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

/*mod_line modifie une ligne de la map designer par nb avec les char de new
N'ecris pas sur un nombre deja change mais verifie la similaritee
nb est un indice; new est une chaine de char ("1234"), possible de sauter un 
char avec un X ("1X34")*/
int	mod_line(int nb, char *new, char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (map[nb][i] != '0' && map[nb][i] != new[i] && new[i] != 'X')
			return (ERROR);
		if (new[i] != 'X')
			map[nb][i] = new[i];
		i++;
	}
	return (SUCCESS);
}
