/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/02 01:25:44 by pruenrua         ###   ########.fr       */
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

	if (ac != 2)
		return (0);
	st_init(&v);
	v.array_yx = file_init(av[1]);
	//lemme_check(v.array_yx);
	if (v.array_yx == NULL)
		return (1);
	count_collectable(&v);
	print_map(v.array_yx);
	printf("out of check col = [%d]\n", v.collectable);
	get_window_size(v.array_yx, &v.m_width, &v.m_hight);
	printf("^^^^^^^^^^^^^[maps here1]^^^^^^^^^^^^^^^\n");
	v.mlx = mlx_init();
	printf("^^^^^^^^^^^^^[maps here1]^^^^^^^^^^^^^^^\n");
	int scale = 32;
	v.mlx_window = mlx_new_window(v.mlx, (v.m_width * scale), (v.m_hight * scale), "TEST");
	mlx_key_hook(v.mlx_window, key_maneger, &v);
	//mlx_loop_hook(v.mlx, change_frame, &v);
	mlx_loop(v.mlx);
}
