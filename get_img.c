/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:40:15 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/10 20:08:55 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_var *v)
{
	t_img	*img;

	img = &v->img[FLOOR];
	img->reference = mlx_xpm_file_to_image(v->mlx, FLOOR_P, &img->size.x, &img->size.y);
	img->pixels = mlx_get_data_addr(img->reference, &img->bits_per_pixel, &img->line_size, &img->endian);
	img = &v->img[WALL];
	img->reference = mlx_xpm_file_to_image(v->mlx, WALL_P, &img->size.x, &img->size.y);
	img->pixels = mlx_get_data_addr(img->reference, &img->bits_per_pixel, &img->line_size, &img->endian);
	img = &v->img[PLAYER];
	img->reference = mlx_xpm_file_to_image(v->mlx, PLAYER_P, &img->size.x, &img->size.y);
	img->pixels = mlx_get_data_addr(img->reference, &img->bits_per_pixel, &img->line_size, &img->endian);
	img = &v->img[COL];
	img->reference = mlx_xpm_file_to_image(v->mlx, COL_P, &img->size.x, &img->size.y);
	img->pixels = mlx_get_data_addr(img->reference, &img->bits_per_pixel, &img->line_size, &img->endian);
	img = &v->img[EXIT];
	img->reference = mlx_xpm_file_to_image(v->mlx, EXIT_P, &img->size.x, &img->size.y);
	img->pixels = mlx_get_data_addr(img->reference, &img->bits_per_pixel, &img->line_size, &img->endian);
}