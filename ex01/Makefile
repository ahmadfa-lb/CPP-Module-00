# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 12:07:47 by afarachi          #+#    #+#              #
#    Updated: 2024/09/15 15:30:17 by afarachi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= phonebook

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= srcs/main.cpp srcs/PhoneBook.cpp srcs/Contact.cpp
OBJ		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean

