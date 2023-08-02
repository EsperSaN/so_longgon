/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:37:31 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/01 22:11:24 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**error(int num)
{
	printf("error [%d] \n", num);
	exit(num);
	return (0);
}

void	free2d(char	**str)
{
	int		i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
	str = NULL;
}

void	free_var(t_var *v)
{
	if (v->array_yx)
	{
		free2d(v->array_yx);
		v->array_yx = NULL;
	}
}