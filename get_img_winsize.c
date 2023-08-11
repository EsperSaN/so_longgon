/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_winsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:40:15 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 11:59:27 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int		img_verify()
//{

//}

void	get_window_size(char **map_array, int *width, int *hight, int img_size)
{
	int	len;

	*width = 0;
	*hight = 0;
	if (!map_array)
		return ((void)error(errno, "CANNOT GET THE WINSIZE SRY"));
	*width = ft_strlen(map_array[0]);
	while (map_array[*hight])
		(*hight)++;
	*width = (*width) * img_size;
	*hight = (*hight) * img_size;
}

int	get_img_data(t_var *v)
{
	t_img	*i;

	i = &v->img[FLOOR];
	i->ref = mlx_xpm_file_to_image(v->mlx, FLOOR_P, &i->size.x, &i->size.y);
	i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
	i = &v->img[WALL];
	i->ref = mlx_xpm_file_to_image(v->mlx, WALL_P, &i->size.x, &i->size.y);
	i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
	i = &v->img[PLAYER];
	i->ref = mlx_xpm_file_to_image(v->mlx, PLAYER_P, &i->size.x, &i->size.y);
	i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
	i = &v->img[COL];
	i->ref = mlx_xpm_file_to_image(v->mlx, COL_P, &i->size.x, &i->size.y);
	i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
	i = &v->img[EXIT];
	i->ref = mlx_xpm_file_to_image(v->mlx, EXIT_P, &i->size.x, &i->size.y);
	i->px = mlx_get_data_addr(i->ref, &i->bit_px, &i->line_size, &i->ed);
	
	return (1);
}