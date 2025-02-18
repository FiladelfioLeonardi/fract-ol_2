# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 21:32:00 by fileonar          #+#    #+#              #
#    Updated: 2025/02/18 10:38:42 by fileonar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

MLX_DIR = ./minilibx-linux/
MLX_LIB = $(MLX_DIR)libmlx.a

NAME = fractol
HEADER = fractol.h
SRC = main.c initialization.c utils.c math_for_scaling.c render.c events.c

OBJS = $(SRC:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

%.o : %.c $(HEADER)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME):  $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(MLXFLAGS) $(HEADER) $(CFLAGS)
	 

clean:
	@rm -rf $(OBJS)
	@make clean -C $(MLX_DIR)
	@echo "Cleaned bin"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned $(NAME)"

re: fclean all

.PHONY: all clean fclean re