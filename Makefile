# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okachkac <okachkac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 22:31:24 by okachkac          #+#    #+#              #
#    Updated: 2025/02/26 14:48:08 by okachkac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
# MLX_FLAGS = -Lminilibx -lmlx -lXext -lX11 -lm
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRC =   main.c \
		player/movement.c \
		player/raycast.c \
		player/raycast_params.c \
		graphics/init_mlx.c \
		graphics/render.c \
		graphics/textures.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c\
		parsing/parsing.c \
		parsing/parsing_utils1.c \
		parsing/parsing_map.c \
		parsing/parsing_utils2.c \
		parsing/parsing_utils3.c \
		parsing/parsing_utils4.c \
		parsing/parsing_utils5.c \
		parsing/parsing_utils6.c \
		parsing/parsing_utils7.c \
		parsing/parsing_utils8.c \
		parsing/parsing_utils9.c \
		parsing/parsing_utils10.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) libft/libft.a $(MLX_FLAGS) -o $(NAME) 


clean:
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean
