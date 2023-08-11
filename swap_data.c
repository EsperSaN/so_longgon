/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:51:04 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 17:09:30 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_after_move(char *from, char *to, int *ret)
{
	if (*to == 'C')
	{
		*to = '0';
		*ret = MV_FIND_COL;
	}
	else if (*to == 'E')
	{
		*to = '0';
		*from = 'p';
		*ret = MV_FIND_EXIT;
	}
}

static void	move_data(char *from, char *to)
{
	char	tmp;

	tmp = *from;
	*from = *to;
	*to = tmp;
}

int	swap_data(char *from, char *to)
{
	int		ret;

	ret = MV_NORM;
	if (*to == '1')
		return (FIND_WALL);
	else if (*from == 'p' && *to == '0')
	{
		*from = 'E';
		*to = 'P';
		return (MV_EXIT_EXIT);
	}
	else if ((*from == 'p' && *to == 'C'))
	{
		*from = 'E';
		*to = 'P';
		return (MV_EEXIT_COL);
	}
	set_after_move(from, to, &ret);
	move_data(from, to);
	return (ret);
}
