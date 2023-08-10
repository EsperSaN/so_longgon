/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:47:45 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/10 23:34:55 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_vector 
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_flood
{
	int	collectable_in_maps;
	int	collected;
	int	exit_find;

}	t_ff;

char	**copy_2d_array(char **array)
{
	int		i;
	int		j;
	char	**ret;
	int		k;

	if (array == NULL)
		return (NULL);
	k = 0;
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
		ret[i] = ft_calloc(j, sizeof(char *));
		if (ret[i] == NULL)
		{
			free2d(ret);
			return (NULL);
		}
	}
	while (array[++i])
	{
		k = -1;
		while (array[i][++k])
			ret[i][k] = array[i][k];
	}
	return (ret);
}

void	flood_fill(char **maps, t_vector pos, int *colled, int *exit_n)
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
	flood_fill(maps, (t_vector){(pos.x - 1), pos.y}, colled, exit_n);
	flood_fill(maps, (t_vector){pos.x, (pos.y - 1)}, colled, exit_n);
	flood_fill(maps, (t_vector){(pos.x + 1), pos.y}, colled, exit_n);
	flood_fill(maps, (t_vector){pos.x, (pos.y + 1)}, colled, exit_n);
}

int	flood_fill_checker(char **maps)
{
	char		**ff_cp;
	int			start_xy[2];
	t_vector	pos;
	t_ff		f;

	f.collectable_in_maps = count_collectable(maps);
	find_the_object_pos(&start_xy, maps, 'P');
	pos.x = start_xy[0];
	pos.y = start_xy[1];
	f.collected = 0;
	f.exit_find = 0;
	ff_cp = NULL;
	ff_cp = copy_2d_array(maps);
	print_map(ff_cp);
	flood_fill(ff_cp, pos, &f.collected, &f.exit_find);
	free2d(ff_cp);
	if (f.exit_find != 1 || f.collected != f.collectable_in_maps)
	{
		printf("ERROR: mission is impossible CODE: can't do the mission\n");
		return (0);
	}
	return (1);
}