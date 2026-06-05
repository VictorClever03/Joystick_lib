# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnanga <vnanga@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/05 15:13:45 by vnanga            #+#    #+#              #
#    Updated: 2026/06/05 15:21:24 by vnanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Joystick
HEADERS = ./includes/joystick.h ./includes/macros.h
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes
RM = rm -rf
SRC = ./src/joystick.c tester.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS): $(HEADERS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re