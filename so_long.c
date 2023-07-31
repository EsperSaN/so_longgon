/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2023/07/31 21:09:57 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	change_frame(t_data var)
// {
		
// }

// void	change_data(t_data *var)
// {
	
// }

// void	init_data(t_data *var, char	*maps)
// {
// 	get_xpm(var);
// 	insert_data(var);
// }

// void	map_checker(char	*maps)
// {
// }
// void	*make_window(t_data var)
// {
// 	void			*window;
// 	unsigned int	width;
// 	unsigned int	hight;

// 	hight = var.imgsize * var.map_hight;
// 	width = var.imgsize * var.map_width;
// 	window = mlx_new_window(var.mlx_var->mlx, hight, width, "HELLOW");

// 	return (window);
// }

// void	put_firstframe(t_data var)
// {
// }

char	**error(int num)
{
	printf("error [%d] \n", num);
	return(0);
}

char	**file_checker(char	*maps)
{
	char	*buff;
	char	*line_of_data;
	int		fd;
	char	**two_array;
	int 	read_count;
	//char	*tmp;

	printf("input = [%s]\n", maps);
	fd = open(maps, O_RDONLY);
	if (fd == -1)
		return (error(errno));
	printf("read complete\n");
	buff = ft_calloc(sizeof(char), (READ_SIZE + 1));
	if (!buff)
		return (error(errno));
	printf("calloc buff complete\n");
	line_of_data = ft_calloc(sizeof(char), 1);
	if (!line_of_data)
		return (error(errno));
	printf("line of data\n");
	read_count = 1;
	while (read_count != 0)
	{
		read_count = read(fd, buff, READ_SIZE);
		line_of_data = ft_strjoin(line_of_data, buff);
	}
	printf("line of data is [%s]\n", line_of_data);
	two_array = ft_split(line_of_data, '\n');
	if (!two_array)
		return (error(errno));
	return (two_array);
}

void	get_window_size(char **map_array, int *width, int *hight)
{
	int len;
	
	*width = 0;
	*hight = 0;
	if (!map_array)
		return ((void)error(errno));
	*width = ft_strlen(map_array[0]);
	while (map_array[*hight])
	{
		len = ft_strlen(map_array[*hight]);
		if(len != *width)
			return((void)error(errno));
		(*hight)++;
	}
}

int	find_char_in_str(char *str,	int c)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return(i);
		i++;
	}
	return (-1);
}

int	change_data(int key ,t_var	*v)
{
	printf("INNNNNNNN\n");
	// char	**data;
	// int		y = 0;
	// int		x = 0;
	
	// data = *m_data;
	// while (data[y])
	// {
	// 	x = find_char_in_str(data[y], 'p');
	// 	y++;
	// }
	// printf("[PLAYER IS AT THE {%d,%d}]\n", x,y);
	if (key != -1)
		printf("user press [%d]\n", key);
	return (1);
}

int	main(int ac, char **av)
{

	t_var	v;
	
	if (ac != 2)
		return (0);
	v.array_yx = file_checker(av[1]);
	printf("out of check\n");

	get_window_size(v.array_yx, &v.m_width, &v.m_hight);
	printf("will make the [%d] x [%d] window \n", v.m_width, v.m_hight);

	v.mlx = mlx_init();
	printf("mlx_init\n");
	
	int i = 0;
	while (v.array_yx[i])
	{
		int j = 0;
		while(v.array_yx[i][j])
		{
			printf("[%c]", v.array_yx[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("^^^^^^^^^^^^^[maps here1]^^^^^^^^^^^^^^^\n");
	int scale = 32;
	v.mlx_window = mlx_new_window(v.mlx, (v.m_width * scale), (v.m_hight * scale), "TEST");
	printf("^^^^^^^^^^^^^[maps here2]^^^^^^^^^^^^^^^\n");
	mlx_key_hook(v.mlx, change_data, &v);
	printf("^^^^^^^^^^^^^[maps here3]^^^^^^^^^^^^^^^\n");
	//mlx_loop_hook(v.mlx, change_frame(), v);
	mlx_loop(v.mlx);
}
