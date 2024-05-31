# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 08:41:08 by akeryan           #+#    #+#              #
#    Updated: 2024/05/31 16:28:30 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec 

CXXFLAGS =  -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -rf

SRC_FILES = main.cpp	\
			Bureaucrat.cpp	\
			AForm.cpp	\
			ShrubberyCreationForm.cpp	\
			RobotomyRequestForm.cpp	\
			PresidentialPardonForm.cpp	

INCLUDE_FILES = AForm.hpp	\
				Bureaucrat.hpp	\
				ShrubberyCreationForm.hpp	\
				RobotomyRequestForm.hpp	\
				PresidentialPardonForm.hpp	

OBJ = $(patsubst %.cpp, %.o, $(SRC_FILES))

%.o: %.cpp $(INCLUDE_FILES) 
	$(CXX) $(CXXFLAGS) -o $@ -c $<  

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
