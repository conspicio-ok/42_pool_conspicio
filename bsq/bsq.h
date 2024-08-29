/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raserre- <raserre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:55:11 by raserre-          #+#    #+#             */
/*   Updated: 2024/07/17 18:39:10 by raserre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef EXIT
#  define SUCCESS 1
#  define ERROR 0
# endif

typedef struct s_map
{
	char			**map;
	int				len;
	char			c_empty;
	char			c_obs;
	char			c_full;
}					t_map;

typedef struct s_squart
{
	unsigned int	x_start;
	unsigned int	y_start;
	unsigned int	size;
}					t_sqrt;

// print.c
void	ft_print_map(char **map);

// call_prog.c
void	ft_freemap(char **map);
void	ft_call_prog(int len, char **maps);

// prog.c
t_sqrt	ft_find_the_sqre(t_map map);
void	ft_put_sqre(t_map map, t_sqrt sqre);

// create_map.c
t_map	create_map(char *str);

// verif_map.c
int		verif_map(t_map map);

// init.c
char	*readtab(char *map_name);

// str.c
int		ft_strlen(char *str);
int		count_line_len(char *str);
char	*ft_strcpyl(char *dest, char *src, int size);

// ft_split.c
char	**ft_split(char *str, char charset);

#endif
