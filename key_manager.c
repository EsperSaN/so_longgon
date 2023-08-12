/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:49 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/12 13:01:37 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	put_stat(t_var *v, int fd)
{
	char	*move;
	char	*collected;
	char	*collectable;

	move = ft_itoa(v->total_mv);
	collectable = ft_itoa(v->collectable);
	collected = ft_itoa(v->collected);
	ft_putstr_fd("MOVE : ", fd);
	ft_putstr_fd(move, fd);
	ft_putstr_fd("\nCOLLECT : ", fd);
	ft_putstr_fd(collected, fd);
	ft_putstr_fd("/", fd);
	ft_putstr_fd(collectable, fd);
	ft_putstr_fd("\n", fd);
	free(collectable);
	free(collected);
	free(move);
}

static void	move_event(t_var *v, int event)
{
	if (event == EXIT_PROGRAM)
		error_exit(0, BYE_MSG, v);
	else if (event == MV_FIND_EXIT)
	{
		v->total_mv += 1;
		if (v->collected == v->collectable)
			error_exit(0, COMPLETE, v);
		v->p_mode = 'p';
	}
	else if (event == MV_EXIT_EXIT)
	{
		v->total_mv += 1;
		v->p_mode = 'P';
	}
	else if (event == MV_EEXIT_COL || event == MV_FIND_COL)
	{
		v->p_mode = 'P';
		v->collected += 1;
		v->total_mv += 1;
	}
	else if (event == MV_NORM)
		v->total_mv += 1;
}

int	key_maneger(int key, t_var *v)
{
	int		r;
	int		p_xy[2];
	char	**data;

	find_the_object_pos(&p_xy, v->array_yx, v->p_mode);
	data = v->array_yx;
	if (key == UP_KEY || key == W)
		r = swap_data(&(data[p_xy[1]][p_xy[0]]), &(data[p_xy[1] - 1][p_xy[0]]));
	if (key == DOWN_KEY || key == S)
		r = swap_data(&(data[p_xy[1]][p_xy[0]]), &(data[p_xy[1] + 1][p_xy[0]]));
	if (key == LEFT_KEY || key == A)
		r = swap_data(&(data[p_xy[1]][p_xy[0]]), &(data[p_xy[1]][p_xy[0] - 1]));
	if (key == RIGHT_KEY || key == D)
		r = swap_data(&(data[p_xy[1]][p_xy[0]]), &(data[p_xy[1]][p_xy[0] + 1]));
	if (key == ESC_KEY)
		r = EXIT_PROGRAM;
	move_event(v, r);
	put_stat(v, 2);
	return (1);
}
