# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:28:58 by kbrousse          #+#    #+#              #
#    Updated: 2023/05/15 14:44:33 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutant

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =	main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*			*"
	@echo "~   Clean terminated	~"
	@echo "*			*"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

fclean: clean 
	@rm -f $(NAME)

re: fclean all

%.o: %.cpp MutantStack.hpp
	@$(CC) $(FLAGS) $< -c -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*				*"
	@echo "~    Compilation terminated	~"
	@echo "*				*"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

.PHONY: all clean fclean re
