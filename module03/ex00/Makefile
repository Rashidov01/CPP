# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 16:28:33 by arashido          #+#    #+#              #
#    Updated: 2023/12/29 16:28:43 by arashido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = main

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# colors
GREEN = \033[92m
YELLOW = \033[93m
GRAY = \033[90m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)$(NAME)$(RESET)$(YELLOW) is ready to use!$(RESET)\n"

%.o: %.cpp
	@$(CXX) $(FLAGS) -c $< -o $@
	@printf "$(GRAY)Compiled $< into $@$(RESET)\n"

clean:
	@rm -f $(OBJS)
	@printf "$(GRAY)$(NAME)$(RESET)$(YELLOW) object files have been deleted!$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(GRAY)$(NAME)$(RESET)$(YELLOW) has been deleted!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
