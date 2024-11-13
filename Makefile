# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:23:34 by nalebrun          #+#    #+#              #
#    Updated: 2024/11/13 16:31:09 by nalebrun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########
##     ##
## var ##
##     ##
#########

CC = cc
FLAGS = -Wall -Werror -Wextra -g
OBJ_DIR = obj

##############
# client var #
##############

CLIENT_TGT = client
CLIENT_SRC_DIR = ./client_src
CLIENT_OBJ_DIR = $(OBJ_DIR)/client

CLIENT_SRC = $(wildcard $(CLIENT_SRC_DIR)/*.c)
CLIENT_OBJ = $(patsubst $(CLIENT_SRC_DIR)/%.c, $(CLIENT_OBJ_DIR)/%.o, $(CLIENT_SRC))



##############
# server var #
##############

SRV_TGT = server
SRV_SRC_DIR = ./server_src
SRV_OBJ_DIR = $(OBJ_DIR)/server

SRV_SRC = $(wildcard $(SRV_SRC_DIR)/*.c)
SRV_OBJ = $(patsubst $(SRV_SRC_DIR)/%.c, $(SRV_OBJ_DIR)/%.o, $(SRV_SRC))



#############
# libft var #
#############

LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a



#################
# ft_printf var #
#################

FTPRINTF_DIR = ./lib/ft_printf
FTPRINTF = $(FTPRINTF_DIR)/ft_printf.a



###########
##       ##
## rules ##
##       ##
###########


all: $(LIBFT) $(FTPRINTF) $(CLIENT_TGT) $(SRV_TGT)

################
# client rules #
################

$(CLIENT_TGT): $(CLIENT_OBJ_DIR) $(CLIENT_OBJ) $(LIBFT) $(FTPRINTF)
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(LIBFT) $(FTPRINTF) -o $(CLIENT_TGT)

$(CLIENT_OBJ_DIR)/%.o: $(CLIENT_SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(CLIENT_OBJ_DIR):
	mkdir -p $(CLIENT_OBJ_DIR)



#############
# srv rules #
#############

$(SRV_TGT): $(SRV_OBJ_DIR) $(SRV_OBJ) $(LIBFT) $(FTPRINTF)
	$(CC) $(FLAGS) $(SRV_OBJ) $(LIBFT) $(FTPRINTF) -o $(SRV_TGT)

$(SRV_OBJ_DIR)/%.o: $(SRV_SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(SRV_OBJ_DIR):
	mkdir -p $(SRV_OBJ_DIR)


###############
# libft rules #
###############

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


###################
# ft_printf rules #
###################

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)


###############
# clean rules #
###############

clean:
	rm -rf $(CLIENT_OBJ_DIR) $(SRV_OBJ_DIR) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -rf $(SRV_TGT) $(CLIENT_TGT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re: fclean all