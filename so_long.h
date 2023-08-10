/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:27:18 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/09 09:13:43 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define READ_SIZE 1
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define ESC_KEY 53
# define W 13
# define S 1
# define A 0
# define D 2
# define FIND_WALL 111
# define FIND_COL 444
# define FIND_EXIT 888
# define EXIT_EXIT 8686
# define EEXIT_COL 8669
# define IMG_SCALE 32

# define FLOOR_P "./img/floor.xpm"
# define WALL_P "./img/wall.xpm"
# define PLAYER_P "./img/player.xpm"
# define COL_P "./img/collectable.xpm"
# define EXIT_P "./img/exit.xpm"

# define FLOOR 0
# define WALL 1
# define PLAYER 2
# define COL 3
# define EXIT 4

typedef struct t_map
{
	int	n_exit;
	int	n_col;
	int	n_ene;
	int	n_tile;
	int	n_wall;
	int	m_width;
}	t_m;

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_image 
{
	void		*reference;
	t_pos		size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_img;

typedef struct t_value
{
	char	**array_yx;
	int		m_width;
	int		m_hight;
	int		collectable;
	int		collected;
	void	*mlx_window;
	void	*mlx;
	char	p_mode;
	char	e_mode;
	void	*frame;
	struct s_image	img[5];
}	t_var;

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

void	get_img(t_var *v);
char	**ft_split(char const *s, char c);
void	free_var(t_var *v);

void	find_the_object_pos(int (*pos)[2], char **maps, char tg);
int		count_collectable(char **maps)
int		count_char_str(char *str, char c);
int		find_char_in_str(char *str,	int c);
int		double_a_check(char	**maps);
int		swap_data(char *c1, char *c2);
void	free2d(char	**str);
int		is_element_exceed(char	*str);
int		is_extention(char	*str, char *extention);

int		flood_fill_checker(char **maps);

char	**error(int num);
void	print_map(char **maps);
void	error_exit(int ernum, char *er_str);

char	**file_init(char	*maps);
int		key_maneger(int key, t_var	*v);
void	get_window_size(char **map_array, int *width, int *hight);
int		change_frame(t_var *v);
#endif