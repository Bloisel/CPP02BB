# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 00:49:30 by bloisel           #+#    #+#              #
#    Updated: 2024/11/26 00:50:11 by bloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Fixed.cpp main.cpp 
NAME =	Fixed 
CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all