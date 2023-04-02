# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 10:35:00 by mhabib-a          #+#    #+#              #
#    Updated: 2023/04/02 03:07:07 by mhabib-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
SRC = philosophers.c tools.c
OBJ = $(SRC:.c=.o)
//CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
LIB = philosophers.h

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(SRC) -o $(NAME)

%.o : %.c $(LIB)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all