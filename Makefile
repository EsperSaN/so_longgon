# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 18:21:34 by pruenrua          #+#    #+#              #
#    Updated: 2023/08/03 19:15:44 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c util_join_str_calloc.c util_split.c swap_data.c error.c key_manager.c mlx_helper.c find_func.c checker.c get_img.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all = $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

mlx_init : 
	@make -C mlx

mlx_clean :
	@make clean -C mlx

re : fclean $(NAME)

.PHONY : clean fclean re