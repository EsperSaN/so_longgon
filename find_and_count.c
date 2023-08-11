/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:11:40 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 15:50:01 by pruenrua         ###   ########.fr       */
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
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			ret += 1;
		str++;
	}
	return (ret);
}

int	is_element_exceed(char	*str)
{
	int	player_c;
	int	exit_c;
	int	collectable_c;

	player_c = count_char_str(str, 'P');
	exit_c = count_char_str(str, 'E');
	collectable_c = count_char_str(str, 'C');
	if (player_c != 1)
	{
		ft_putstr_fd("ONLY one player are accept\n", 2);
		return (1);
	}
	if (exit_c != 1)
	{
		ft_putstr_fd("ONLY one exit are accept\n", 2);
		return (1);
	}
	if (collectable_c <= 0)
	{
		ft_putstr_fd("ONLY 1 collectable or more are accept\n", 2);
		return (1);
	}
	return (0);
}

int	count_char_in_maps(char **maps, char c)
{
	int		y;
	int		find;

	if (!maps || !c)
		return (0);
	y = 0;
	find = 0;
	while (maps[y])
	{
		find += count_char_str(maps[y], c);
		y++;
	}
	return (find);
}