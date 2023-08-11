/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_winsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:40:15 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 15:46:11 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_window_size(char **map_array, int *width, int *hight, int img_size)
{
	int	len;

	*width = 0;
	*hight = 0;
	*width = ft_strlen(map_array[0]);
	while (map_array[*hight])
		(*hight)++;
	*width = (*width) * img_size;
	*hight = (*hight) * img_size;
}

static int	get_xpm(t_var *v)
{
	t_img	*i;
	int		j;

	i = &v->img[FLOOR];
	i->ref = mlx_xpm_file_to_image(v->mlx, FLOOR_P, &i->size.x, &i->size.y);
	i = &v->img[WALL];
	i->ref = mlx_xpm_file_to_image(v->mlx, WALL_P, &i->size.x, &i->size.y);
	i = &v->img[PLAYER];
	i->ref = mlx_xpm_file_to_image(v->mlx, PLAYER_P, &i->size.x, &i->size.y);
	i = &v->img[COL];
	i->ref = mlx_xpm_file_to_image(v->mlx, COL_P, &i->size.x, &i->size.y);
	i = &v->img[EXIT];
	i->ref = mlx_xpm_file_to_image(v->mlx, EXIT_P, &i->size.x, &i->size.y);
	j = -1;
	while (++j < 5)
	{
		if (v->img[j].ref == NULL || v->img[j].size.x != IMG_SIZE 
			|| v->img[j].size.x != IMG_SIZE)
			return (0);
	}
	return (1);
}

int	get_img_data(t_var *v)
{
	t_img	*i;
	int		j;

	if (get_xpm(v))
	{
		i = &v->img[FLOOR];
		i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
		i = &v->img[WALL];
		i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
		i = &v->img[PLAYER];
		i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
		i = &v->img[COL];
		i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
		i = &v->img[EXIT];
		i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
		v->imgsize = v->img[0].size.x;
		return (1);
	}
	return (0);
}