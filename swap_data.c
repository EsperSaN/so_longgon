/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:51:04 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/01 21:40:30 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	swap_data(char *from, char *to)
{
	char	tmp;
	int		ret;

	ret = 0;
	if (*to == '1')
		return (FIND_WALL);
	else if (*from == 'p' && *to == 'C')
	{
		*from = 'E';
		*to = 'P';
		return (EEXIT_COL);
	}
	else if ((*from == 'p' && *to == '0'))
	{
		*from = 'E';
		*to = 'P';
		return (EXIT_EXIT);
	}
	else if (*to == 'C')
	{
		ret = FIND_COL;
		*to = '0';
	}
	else if (*to == 'E')
	{
		*to = '0';
		*from = 'p';
		ret = FIND_EXIT;
	}
	tmp = *from;
	*from = *to;
	*to = tmp;
	return (ret);
}
