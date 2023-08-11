/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:47:45 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 11:44:17 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_2d_array(char **array)
{
	int		i;
	int		j;
	char	**ret;

	if (array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (array[i][j])
		j++;
	while (array[i])
		i++;
	ret = ft_calloc(i + 1, sizeof(char **));
	if (!ret)
		return (NULL);
	while (array[--i] && i >= 0)
	{
		ret[i] = ft_substr(array[i], 0, ft_strlen(array[i]));
		if (ret[i] == NULL)
		{
			free2d(ret);
			return (NULL);
		}
	}
	return (ret);
}

static void	flood_fill(char **maps, t_pos pos, int *colled, int *exit_n)
{
	if (!maps)
		return ;
	if (pos.y < 0 || pos.x < 0 
		|| maps[pos.y][pos.x] == '1' || maps[pos.y][pos.x] == 'F')
		return ;
	if (maps[pos.y][pos.x] == 'C')
		*colled = *colled + 1;
	if (maps[pos.y][pos.x] == 'E')
		*exit_n = *exit_n + 1;
	maps[pos.y][pos.x] = '1';
	flood_fill(maps, (t_pos){(pos.x - 1), pos.y}, colled, exit_n);
	flood_fill(maps, (t_pos){pos.x, (pos.y - 1)}, colled, exit_n);
	flood_fill(maps, (t_pos){(pos.x + 1), pos.y}, colled, exit_n);
	flood_fill(maps, (t_pos){pos.x, (pos.y + 1)}, colled, exit_n);
}

int	flood_fill_checker(char **maps)
{
	char		**ff_cp;
	int			start_xy[2];
	t_pos		pos;
	t_ff		f;

	f.collectable_in_maps = count_char_in_maps(maps, 'C');
	find_the_object_pos(&start_xy, maps, 'P');
	pos.x = start_xy[0];
	pos.y = start_xy[1];
	f.collected = 0;
	f.exit_find = 0;
	ff_cp = NULL;
	ff_cp = copy_2d_array(maps);
	flood_fill(ff_cp, pos, &f.collected, &f.exit_find);
	free2d(ff_cp);
	if (f.exit_find != 1 || f.collected != f.collectable_in_maps)
	{
		printf("ERROR: mission is impossible CODE: can't do the mission\n");
		return (0);
	}
	return (1);
}