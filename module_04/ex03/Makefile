# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:28:58 by kbrousse          #+#    #+#              #
#    Updated: 2023/04/14 17:21:49 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =	AMateria.cpp		\
		Ice.cpp				\
		Cure.cpp			\
		ICharacter.cpp		\
		Character.cpp		\
		IMateriaSource.cpp	\
		MateriaSource.cpp	\
		main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS =	AMateria.hpp		\
			Ice.hpp				\
			Cure.hpp			\
			ICharacter.hpp		\
			IMateriaSource.hpp	\
			MateriaSource.hpp	\
			Character.hpp

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

%.o: %.cpp $(HEADERS)
	@$(CC) $(FLAGS) $< -c -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*				*"
	@echo "~    Compilation terminated	~"
	@echo "*				*"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

.PHONY: all clean fclean re
