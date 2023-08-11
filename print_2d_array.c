/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2d_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:26:38 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 10:26:57 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **maps)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (maps[y])
	{
		x = 0;
		while (maps[y][x])
		{
			printf("[%c]", maps[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}