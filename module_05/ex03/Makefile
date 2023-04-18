# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:28:58 by kbrousse          #+#    #+#              #
#    Updated: 2023/04/18 18:24:25 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =	Bureaucrat.cpp				\
		AForm.cpp					\
		ShrubberyCreationForm.cpp	\
		RobotomyRequestForm.cpp		\
		PresidentialPardonForm.cpp	\
		main.cpp

HEADERS =	Bureaucrat.hpp				\
			AForm.hpp					\
			ShrubberyCreationForm.hpp	\
			RobotomyRequestForm.hpp		\
			PresidentialPardonForm.hpp

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
