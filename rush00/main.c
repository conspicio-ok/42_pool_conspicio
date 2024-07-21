/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:19:34 by raserre-          #+#    #+#             */
/*   Updated: 2024/06/30 19:22:01 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	simple_atoi(char *nbr)
{
	int	nb;

	nb = 0;
	while ((*nbr >= '0' && *nbr <= '9') || *nbr == '-')
	{
		if (*nbr == '-')
			nbr++;
		nb = nb * 10 + *nbr - '0';
		nbr++;
	}
	return (nb);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
		return (0);
	x = simple_atoi(argv[1]);
	y = simple_atoi(argv[2]);
	rush(x, y);
	return (0);
}
