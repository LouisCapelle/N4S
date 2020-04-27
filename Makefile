##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

NAME	= ai

CC	= gcc -g

RM	= rm -f

SRCS	= ./src/main.c 				\
		  ./src/free_tab.c 			\
		  ./src/str_to_word_tab.c 	\
		  ./src/my_strdup.c 		\
		  ./src/my_strlen.c 		\
		  ./src/communication.c		\
		  ./src/movement_ai.c


OBJS	= $(SRCS:.c=.o)

CFLAGS = -I  ./include
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

