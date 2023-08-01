/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:11:40 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/01 21:50:22 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_the_object_pos(int (*pos)[2], char **maps, char tg)
{
	int	x;
	int	y;
	int	find;

	find = 0;
	x = 0;
	y = 0;
	while (maps[y] && find == 0)
	{
		y++;
		printf("here\n");
		x = find_char_in_str(maps[y], tg);
		if (x > 0)
			find = 1;
		else if (find == -1)
			return ;
	}
	(*pos)[0] = x;
	(*pos)[1] = y;
}

int	find_char_in_str(char *str,	int c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	count_char_str(char *str, char c)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (*str == c)
			ret += 1;
		str++;
	}
	return (ret);
}

void	count_collectable(t_var *v)
{
	char	**map_data;
	int		y;
	int		find;

	map_data = v->array_yx;
	y = 0;
	find = 0;
	while (map_data[y])
	{
		find += count_char_str(map_data[y], 'C');
		y++;
	}
	v->collectable = find;
}