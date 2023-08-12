# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 18:21:34 by pruenrua          #+#    #+#              #
#    Updated: 2023/08/12 13:24:06 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = error_free.c flood_fill.c key_manager.c so_long.c swap_data.c \
	array_checker.c file_init.c get_img_winsize.c util_join_str_calloc.c \
	change_frame.c find_and_count.c util_split.c ft_itoa.c

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
	make -C mlx

mlx_clean :
	make clean -C mlx
norm :
	norminette $(SRC)
	
re : fclean $(NAME)

.PHONY : clean fclean re norm mlx_clean mlx_init