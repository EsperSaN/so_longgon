/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:27:18 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/12 13:05:29 by pruenrua         ###   ########.fr       */
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

# define TITLE "SO_LONGON"
# define READ_SIZE 1
# define IMG_SIZE 32
# define FLOOR_P "./img/floor.xpm"
# define WALL_P "./img/wall.xpm"
# define PLAYER_P "./img/player.xpm"
# define COL_P "./img/collectable.xpm"
# define EXIT_P "./img/exit.xpm"

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
# define MV_FIND_COL 444
# define MV_FIND_EXIT 888
# define MV_EXIT_EXIT 8686
# define MV_EEXIT_COL 8669
# define MV_NORM 2543
# define EXIT_PROGRAM 403

# define FLOOR 0
# define WALL 1
# define PLAYER 2
# define COL 3
# define EXIT 4

//# define COMPLETE "Error\n"
//# define MAPS_ERR "Error\n"
//# define MISS_FAIL "Error\n"
//# define IMG_ERR "Error\n"
//# define BYE_MSG "Error\n"
# define COMPLETE "ROSE ARE RED VIOLET ARE BLUE MISSON IS SUCCESFUL : THX YOU\n"
# define MAPS_ERR "MAPS ERROR : PLZ CHECK YOUR CONTENT ON MAP\n"
# define MISS_FAIL "MAPS ERROR : Even ChatGPT can't complete this maps\n"
# define IMG_ERR "MAPS ERROR : IMAGE / SIZE NOT GOOD plz check you file/header\n"
# define BYE_MSG "USER ERROR : YOU EXIT BEFORE THE GAME END UwU\n"

typedef struct s_flood
{
	int	collectable_in_maps;
	int	collected;
	int	exit_find;

}	t_ff;

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_image 
{
	void		*ref;
	t_pos		size;
	char		*px;
	int			bit_px;
	int			line_size;
	int			ed;
}				t_img;

typedef struct s_read
{
	char	*buff;
	char	*ret;
	int		read_count;
	char	*tmp;
}			t_read;

typedef struct s_value
{
	char			**array_yx;
	int				win_w;
	int				win_h;
	int				imgsize;
	int				collectable;
	int				collected;
	void			*window;
	void			*mlx;
	char			p_mode;
	int				total_mv;
	void			*frame;
	struct s_image	img[5];
}	t_var;

/* file init */
char	**file_init(char	*maps);
void	st_init(t_var *v);

/* array checker */
int		array_checker(char	**maps);
int		is_all_char(char *str, char c);
int		is_char_in_set(char	*maps_line, char *allowlist);

/* ff_floodfill */
int		flood_fill_checker(char **maps);

/* find and count */
int		count_char_in_maps(char **maps, char c);
int		is_element_exceed(char	*str);
int		count_char_str(char *str, char c);
void	find_the_object_pos(int (*pos)[2], char **maps, char tg);
int		find_char_in_str(char *str,	int c);

/* get img_data and winsize */
void	get_window_size(char **map_array, int *width, int *hight, int img_size);
int		get_img_data(t_var *v);

/* swap_data */
int		swap_data(char *from, char *to);

/* key_manager */
int		key_maneger(int key, t_var	*v);

/* change frame */
int		change_frame(t_var *v);

/* util_join_calloc */
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

/* util_split */
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* ft_itoa */
char	*ft_itoa(int n);

/* error and free */
char	**error(int num, char *str);
void	ft_putstr_fd(char *str, int fd);
void	free2d(char	**str);
void	free_var(t_var *v);
void	error_exit(int ernum, char *er_str, t_var *v);

#endif