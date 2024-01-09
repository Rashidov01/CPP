# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 14:01:27 by arashido          #+#    #+#              #
#    Updated: 2024/01/09 15:12:13 by arashido         ###   ########.fr        #
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
	@printf "$(GREEN)$(NAME)$(RESET)$(YELLOW) is ready to use!$(RESET)\n"

$(OBJDIR)/%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "$(GRAY)Compiled $< into $@$(RESET)\n"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@printf "$(GRAY)$(OBJDIR)$(RESET)$(YELLOW) folder has been deleted!$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(GRAY)$(NAME)$(RESET)$(YELLOW) has been deleted!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
