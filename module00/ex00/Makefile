# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 08:45:03 by arashido          #+#    #+#              #
#    Updated: 2024/01/09 15:20:01 by arashido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# colors
GREEN = \033[92m
YELLOW = \033[93m
GRAY = \033[90m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME)$(RESET)$(YELLOW) is ready to use!$(RESET)"

%.o: %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "$(GRAY)Compiled $< into $@$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(GRAY)$(NAME)$(RESET)$(YELLOW) object files have been deleted!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GRAY)$(NAME)$(RESET)$(YELLOW) has been deleted!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
