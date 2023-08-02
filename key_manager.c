/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:17:49 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/02 15:49:19 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_maneger(int key ,t_var	*v)
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
	if (r == FIND_WALL)
		printf("WALL!!!\n");
	else if (r == FIND_COL)
	{
		printf("COLLECT!!\n");
		v->collected += 1;
	}
	else if (r == FIND_EXIT)
	{
		if (v->collected == v->collectable)
		{
			printf("[CONGREAT TU LATIONNNNNNNNNNNNNNNNNNNNN!!!!!!]\n");
			free_var(v);
			error(22);
		}
		v->p_mode = 'p';
		printf("EXIT!!!\n");
	}
	else if (r == EXIT_EXIT)
	{
		v->p_mode = 'P';
		printf("EXITTTTTTEXITTT!!!\n");
	}
	else if (r == EEXIT_COL)
	{
		v->p_mode = 'P';
		printf("COLLECT!!\n");
		v->collected += 1;
	}
	else
		printf("walk\n");
	print_map(v->array_yx);
	printf("theplayer[%c] position is [%d,%d] collect [%d]\n",v->p_mode, p_xy[0], p_xy[1], v->collected);
	return (1);
}