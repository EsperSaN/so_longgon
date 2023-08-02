/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:38:23 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/02 16:38:00 by pruenrua         ###   ########.fr       */
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

int	change_frame(t_var *v)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	//v->frame = mlx_new_image(v->mlx, v->m_width, v->m_hight);
	while (v->array_yx[y])
	{
		mlx_string_put(v->mlx, v->mlx_window, (IMG_SCALE * 1), y * IMG_SCALE, 0x00FF0000, v->array_yx[y]);
		x++;
		y++;
	}
	//mlx_destroy_image(v->mlx, v->frame);
	return (0);
}