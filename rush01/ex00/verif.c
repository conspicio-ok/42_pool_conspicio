/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:22:22 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/06 10:43:57 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

/*verif_argv verifie si la base pour faire le skyscraper est correct,
si elle est juste, elle renvoie la longueur du carre,
sinon elle renvoie une erreur*/
int	verif_argv(char *str)
{
	int	size;
	int	count;

	size = 2;
	count = 0;
	if ('0' <= str[0] && str[0] <= '9')
		count++;
	while (str[size])
	{
		if (str[size - 1] == ' ' && '0' <= str[size] && str[size] <= '9')
		{
			count++;
			if (str[size + 1] != '\0')
				size += 2;
			else
				size++;
		}
		else
			return (ERROR);
	}
	size = count / 4;
	count = count % 4;
	if (count != 0)
		return (ERROR);
	return (size);
}

/*verif_number utilise verif_argv et regarde en plus si aucun nombre 
est plus grand que la size*/
int	verif_number(char *num_argv)
{
	int	i;
	int	size;

	i = 0;
	size = verif_argv(num_argv);
	if (size == ERROR)
		return (ERROR);
	while (num_argv[i])
	{
		if (num_argv[i] > size + '0')
			return (ERROR);
		i++;
	}
	return (size);
}
