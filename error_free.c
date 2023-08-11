/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:37:31 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 11:36:49 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

char	**error(int num, char *str)
{
	ft_putstr_fd(str, 2);
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

void	error_exit(int ernum, char *er_str)
{
	if (*er_str)
		write(2, er_str, ft_strlen(er_str));
	exit(ernum);
}