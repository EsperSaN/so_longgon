/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:47:45 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/09 09:15:19 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(char **maps, int x, int y, int *colled, int *exit_n)
{
	if (!maps[y][x] || maps[y][x] == '1')
		return ;
	if (maps[y][x] == 'C')
		*colled += 1;
	if (maps[y][x] == 'E')
		*exit_find += 1;
	flood_fill(maps, x + 1, y, colled, exit_find);
	flood_fill(maps, x, y + 1, colled, exit_find);
	flood_fill(maps, x - 1, y, colled, exit_find);
	flood_fill(maps, x, y - 1, colled, exit_find);
}

int	flood_fill_checker(char **maps)
{
	int collected;
	int exit_find;
	int start_xy[2];
	int collectable_in_maps;

	collectable_in_maps = count_collectable(maps);
	find_the_object_pos(&start_xy, maps, "P");

	flood_fill(maps, start_xy[0], start_xy[1], &collected, &exit_find);
	printf("the C in the maps is [%d] \nafter FF col [%d] exit [%d]", collectable_in_maps, collected,exit_find);
	if (exit_find != 1 || collected != collectable_in_maps)
	{
		printf("ERROR: mission is impossible CODE: can't do the mission\n");
		return (0);
	}
	return (1);
}