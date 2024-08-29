NAME		= bsq
CC			= cc
WFLAGS		= -Wall -Werror -Wextra
SRC			= call_prog.c create_map.c ft_split.c init.c main.c print.c prog.c str.c verif_map.c
OBJ			= $(SRC:.c=.o)
RM			= rm -f

$(NAME):	$(OBJ)
	$(CC) $(WFLAGS) $^ -o $(NAME)


all:		$(NAME)

.c.o:
	$(CC) $(WFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) $(NAME)

re:		fclean all