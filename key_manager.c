/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:49 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 14:56:37 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (r == FIND_EXIT)
	{
		if (v->collected == v->collectable)
			error_exit(0, COMPLETE, v->array_yx);
		v->p_mode = 'p';
	}
	else if (r == EXIT_EXIT)
		v->p_mode = 'P';
	else if (r == EEXIT_COL || r == FIND_COL)
	{
		v->p_mode = 'P';
		v->collected += 1;
	}
	return (1);
}