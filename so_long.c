/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/10 23:39:57 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_extention(char	*str, char *extention)
{
	int	len;
	int	ex_len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	ex_len = ft_strlen(extention);
	if (len < ex_len)
		return (0);
	len = len - 1;
	ex_len = ex_len - 1;
	while (extention[ex_len])
	{
		if (str[len] != extention[ex_len])
			return (0);
		len--;
		ex_len--;
	}
	return (1);
}

void	st_init(t_var *v)
{
	v->array_yx = NULL;
	v->m_h = 0;
	v->m_w = 0;
	v->collectable = 0;
	v->collected = 0;
	v->mlx = NULL;
	v->mlx_window = NULL;
	v->p_mode = 'P';
	v->e_mode = 'E';
	v->frame = NULL;
}

int	main(int ac, char **av)
{
	t_var	v;

	if (ac != 2)
		return (0);
	st_init(&v);
	v.array_yx = file_init(av[1]);
	if (v.array_yx == NULL)
		error_exit(1, "Error please check your maps content\n");
	if (double_a_check(v.array_yx))
	{
		free2d(v.array_yx);
		error_exit(1, "Error please check you maps content\n");
	}
	v.collectable = count_collectable(v.array_yx);
	get_window_size(v.array_yx, &v.m_w, &v.m_h);
	v.mlx = mlx_init();
	v.mlx_window = mlx_new_window(v.mlx, (v.m_w * P_SIZE), (v.m_h * P_SIZE), "TEST");
	get_img(&v);
	mlx_key_hook(v.mlx_window, key_maneger, &v);
	mlx_loop_hook(v.mlx, change_frame, &v);
	mlx_loop(v.mlx);
}
