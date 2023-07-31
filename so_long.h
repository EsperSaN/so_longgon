/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:27:18 by pruenrua          #+#    #+#             */
/*   Updated: 2023/07/31 21:06:24 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define READ_SIZE 1

typedef struct t_value
{
	char 	**array_yx;
	int		m_width;
	int		m_hight;
	void	*mlx_window;
	void	*mlx;
}	t_var;

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

char	**ft_split(char const *s, char c);
#endif