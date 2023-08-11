/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 15:35:19 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	st_init(t_var *v)
{
	v->array_yx = NULL;
	v->win_h = 0;
	v->win_h = 0;
	v->collectable = 0;
	v->collected = 0;
	v->mlx = NULL;
	v->window = NULL;
	v->p_mode = 'P';
	v->e_mode = 'E';
	v->frame = NULL;
	v->imgsize = 0;
}

int	main(int ac, char **av)
{
	t_var	v;

	if (ac != 2)
		return (0);
	st_init(&v);
	v.array_yx = file_init(av[1]);
	if (v.array_yx == NULL)
		error_exit(1, MAPS_ERR, v.array_yx);
	if (array_checker(v.array_yx))
		error_exit(1, MAPS_ERR, v.array_yx);
	v.mlx = mlx_init();
	if (!get_img_data(&v))
		error_exit(1, IMG_ERR, v.array_yx);
	v.collectable = count_char_in_maps(v.array_yx, 'C');
	get_window_size(v.array_yx, &v.win_w, &v.win_h, v.imgsize);
	v.window = mlx_new_window(v.mlx, v.win_w, v.win_h, TITLE);
	mlx_key_hook(v.window, key_maneger, &v);
	mlx_loop_hook(v.mlx, change_frame, &v);
	mlx_loop(v.mlx);
}
