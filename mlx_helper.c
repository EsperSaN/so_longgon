/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:38:23 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/03 19:33:10 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_window_size(char **map_array, int *width, int *hight)
{
	int	len;

	*width = 0;
	*hight = 0;
	if (!map_array)
		return ((void)error(errno));
	*width = ft_strlen(map_array[0]);
	while (map_array[*hight])
	{
		len = ft_strlen(map_array[*hight]);
		if (len != *width)
			return ((void)error(errno));
		(*hight)++;
	}
}

void	put_pic(t_var v ,int x, int y, int mode)
{
	t_img img;

	img = v.img[mode];
	
	mlx_put_image_to_window(v.mlx, v.mlx_window,img.reference, x * 32, y * 32);
	printf ("put the img at [%d] [%d]\n", x , y);
}

int	change_frame(t_var *v)
{
	int y;
	int x;

	y = 0;
	while (v->array_yx[y])
	{
		x = 0;
		while (v->array_yx[y][x])
		{
			put_pic(*v, x, y, FLOOR);
			if (v->array_yx[y][x] == '1')
				put_pic(*v, x, y, WALL);
			if (v->array_yx[y][x] == 'C')
				put_pic(*v, x, y, COL);
			if (v->array_yx[y][x] == 'p')
			{
				put_pic(*v, x, y, EXIT);
				put_pic(*v, x, y, PLAYER);
			}
			if (v->array_yx[y][x] == 'P')
				put_pic(*v, x, y, PLAYER);
			if (v->array_yx[y][x] == 'E')
				put_pic(*v, x, y, EXIT);
			x++;
		}
		y++;
	}
	return (0);
}