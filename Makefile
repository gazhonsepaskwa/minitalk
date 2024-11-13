# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:23:34 by nalebrun          #+#    #+#              #
#    Updated: 2024/11/13 14:35:01 by nalebrun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# var

CC = cc
FLAGS = -Wall -Werror -Wextra -g

##############
# client var #
##############

CLIENT_TGT = client
CLIENT_SRC_DIR = ./client
CLIENT_OBJ_DIR = client_obj

CLIENT_SRC = $(wildcard $(CLIENT_SRC_DIR)/*.c)
CLIENT_OBJ = $(patsubst $(CLIENT_SRC_DIR)/%.c, $(CLIENT_OBJ_DIR)/%.o, $(CLIENT_SRC))



##############
# server var #
##############

SRV_TGT = server
SRV_SRC_DIR = ./server
SRV_OBJ_DIR = srv_obj

SRV_SRC = $(wildcard $(SRV_SRC_DIR)/*.c)
SRV_OBJ = $(patsubst $(SRV_SRC_DIR)/%.c, $(SRV_OBJ_DIR)/%.o, $(SRV_SRC))

##############
# libft var  #
##############

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a



# rules

all: $(CLIENT_TGT) $(SRV_TGT)

################
# client rules #
################

$(CLIENT_TGT): $(CLIENT_OBJ_DIR) $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(CLIENT_TGT)

$(CLIENT_OBJ_DIR)/%.o: $(CLIENT_SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(CLIENT_OBJ_DIR):
	mkdir -p $(CLIENT_OBJ_DIR)



#############
# srv rules #
#############

$(SRV_TGT): $(SRV_OBJ_DIR) $(SRV_OBJ)
	$(CC) $(FLAGS) $(SRV_OBJ) -o $(SRV_TGT)

$(SRV_OBJ_DIR)/%.o: $(SRV_SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(SRV_OBJ_DIR):
	mkdir -p $(SRV_OBJ_DIR)


###############
# libft rules #
###############

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


###############
# clean rules #
###############

clean:
	rm -rf $(CLIENT_OBJ_DIR) $(SRV_OBJ_DIR)

fclean: clean
	rm -rf $(SRV_TGT) $(CLIENT_TGT)