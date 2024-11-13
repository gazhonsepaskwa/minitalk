# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 13:19:19 by nalebrun          #+#    #+#              #
#    Updated: 2024/11/13 15:20:03 by nalebrun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSDIR = srcs
INCDIR = ./
OBJDIR = obj

SRCS = ft_printf.c utils.c utils2.c

OBJS = $(OBJDIR)/ft_printf.o $(OBJDIR)/utils.o $(OBJDIR)/utils2.o

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

NAME = ft_printf.a

all: $(NAME)

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -I $(INCDIR) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
