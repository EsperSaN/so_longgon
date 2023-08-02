/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/02 17:43:51 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	st_init(t_var *v)
{
	v->array_yx = NULL;
	v->m_hight = 0;
	v->m_width = 0;
	v->collectable = 0;
	v->collected = 0;
	v->mlx = NULL;
	v->mlx_window = NULL;
	v->p_mode = 'P';
	v->e_mode = 'E';
}

int	main(int ac, char **av)
{
	t_var	v;
	t_img	img;

	if (ac != 2)
		return (0);
	st_init(&v);
	v.array_yx = file_init(av[1]);
	if (double_a_check(v.array_yx))
	{
		free2d(v.array_yx);
		error(98);
	}
	if (v.array_yx == NULL)
		return (1);
	count_collectable(&v);
	get_window_size(v.array_yx, &v.m_width, &v.m_hight);
	printf("map width is [%d] hight is [%d]\n", v.m_width, v.m_hight);
	v.mlx = mlx_init();
	v.mlx_window = mlx_new_window(v.mlx, (v.m_width * IMG_SCALE), (v.m_hight * IMG_SCALE), "TEST");
	img.reference = mlx_xpm_file_to_image(v.mlx, "./glassfloor.xpm", &img.size.x, &img.size.y);
	printf("the adr is [%p] size [%d] x [%d]\n", img.reference, img.size.x, img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	printf("pixel is [%s] have [%d] per pixel [%d] line_size [%d] endian\n", img.pixels, img.bits_per_pixel, img.line_size, img.bits_per_pixel);
	mlx_put_image_to_window(v.mlx, v.mlx_window,img.reference, 32, 32);
	mlx_key_hook(v.mlx_window, key_maneger, &v);
	//mlx_loop_hook(v.mlx, change_frame, &v);
	mlx_loop(v.mlx);
}
