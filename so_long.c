/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/12 13:09:04 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_program(t_var *v)
{
	error_exit(0, BYE_MSG, v);
	return (1);
}

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
	v->total_mv = 0;
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
		error_exit(1, MAPS_ERR, &v);
	if (array_checker(v.array_yx))
		error_exit(1, MAPS_ERR, &v);
	v.mlx = mlx_init();
	if (!get_img_data(&v))
		error_exit(1, IMG_ERR, &v);
	v.collectable = count_char_in_maps(v.array_yx, 'C');
	get_window_size(v.array_yx, &v.win_w, &v.win_h, v.imgsize);
	v.window = mlx_new_window(v.mlx, v.win_w, v.win_h, TITLE);
	mlx_hook(v.window, 17, 1L << 0, close_program, &v);
	mlx_key_hook(v.window, key_maneger, &v);
	mlx_loop_hook(v.mlx, change_frame, &v);
	mlx_loop(v.mlx);
}
