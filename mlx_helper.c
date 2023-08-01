/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:38:23 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/01 16:39:43 by pruenrua         ###   ########.fr       */
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

	y = 0;
	while (v->array_yx[y])
	{
		printf("|%s|\n", v->array_yx[y]);
		y++;
	}
	return (0);
}