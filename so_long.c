/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2023/07/25 23:26:23 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_frame(t_data var)
{
		
}

void	change_data(t_data *var)
{
	
}

void	init_data(t_data *var, char	*maps)
{
	get_xpm(var);
	insert_data(var);
}

void	map_checker(char	*maps)
{
}
void	*make_window(t_data var)
{
	void			*window;
	unsigned int	width;
	unsigned int	hight;

	hight = var.imgsize * var.map_hight;
	width = var.imgsize * var.map_width;
	window = mlx_new_window(var.mlx_var->mlx, hight, width, "HELLOW");

	return (window);
}

void	put_firstframe(t_data var)
{
}

int	main(int ac, char **av)
{
	t_data	var;
	void	*mlx;
	void	*img;
	void	*window;

	if (ac != 2)
		return (0);
	map_checker(av[1]);
	init_data(&var, av[1]);
	put_firstframe(var);
	mlx = mlx_init();
	window = mlx_new_window(mlx, (var.imgsize * var.map_hight), (var.imgsize * var.map_width), "TEST");
	mlx_key_hook(mlx, change_data(), var);
	mlx_loop_hook(mlx, change_frame(), var);
	mlx_loop(mlx);
}
