/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:38:23 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 11:34:14 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_pic(t_var v, int x, int y, int mode)
{
	t_img	img;
	int		pos_x;
	int		pos_y;

	pos_x = x * v.imgsize;
	pos_y = y * v.imgsize;
	img = v.img[mode];
	mlx_put_image_to_window(v.mlx, v.window, img.ref, pos_x, pos_y);
}

int	change_frame(t_var *v)
{
	int	y;
	int	x;

	y = -1;
	while (v->array_yx[++y])
	{
		x = -1;
		while (v->array_yx[y][++x])
		{
			put_pic(*v, x, y, FLOOR);
			if (v->array_yx[y][x] == '1')
				put_pic(*v, x, y, WALL);
			if (v->array_yx[y][x] == 'C')
				put_pic(*v, x, y, COL);
			if (v->array_yx[y][x] == 'E' || v->array_yx[y][x] == 'p')
				put_pic(*v, x, y, EXIT);
			if (v->array_yx[y][x] == 'P' || v->array_yx[y][x] == 'p')
				put_pic(*v, x, y, PLAYER);
		}
	}
	return (0);
}
