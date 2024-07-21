#ifndef SKY_H
# define SKY_H

#define ERROR 1
#define SUCCESS 0

// rush01.c
int     rush01(int size, char *num_input);

// verif.c
int	verif_number(char *num_argv);

// ft_print.c
void	ft_putstr(char *str);
void	print_map(char **map, int size);

// map.c
char	*create_str(int size);
char	**create_map(int size);
void	free_map(char **map, int size);
void	free_str(char *line);

// modif_map.c
int    mod_line(int nb, char *new, char **map, int size);

// look.c
char	*r_look_line(char **map, int line, int size);
char	*l_look_line(char **map, int line, int size);
char	*up_look_col(char **map, int col, int size);
char    *down_look_col(char **map, int col, int size);

// check.c
int	check_char(char *str);
int	check_line(char **map, int line, int size, char *cond);
int	check(char **map, char *num_input, int size);

#endif
