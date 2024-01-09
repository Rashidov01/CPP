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

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = main

SRCS = $(wildcard *.cpp)
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

# colors
GREEN = \033[92m
YELLOW = \033[93m
GRAY = \033[90m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME)$(RESET)$(YELLOW) is ready to use!$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GRAY)Compiled $< into $@$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "$(GRAY)$(OBJDIR)$(RESET)$(YELLOW) folder has been deleted!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GRAY)$(NAME)$(RESET)$(YELLOW) has been deleted!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
