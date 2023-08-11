/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:10:25 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 10:28:42 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_char_in_set(char	*maps_line, char	*allowlist)
{
	int	i;
	int	j;
	int	find;

	i = 0;
	find = 0;
	while (maps_line[i])
	{
		j = 0;
		find = 0;
		while (allowlist[j])
		{
			if (maps_line[i] == allowlist[j])
				find = 1;
			j++;
		}
		if (find == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_all_char(char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

int	array_checker(char	**maps)
{
	int	width;
	int	hight;
	int	len;

	if (!maps)
		return (1);
	width = ft_strlen(maps[0]);
	hight = -1;
	while (maps[++hight])
	{
		len = ft_strlen(maps[hight]);
		if (len != width || !is_char_in_set(maps[hight], "CPE01\n"))
			return (1); 
	}
	if (!is_all_char(maps[0], '1') || !is_all_char(maps[hight - 1], '1'))
		return (1);
	hight = -1;
	while (maps[++hight])
	{
		if (maps[hight][0] != '1' || maps[hight][width - 1] != '1')
			return (1);
	}
	if (!flood_fill_checker(maps))
		return (1);
	return (0);
}
