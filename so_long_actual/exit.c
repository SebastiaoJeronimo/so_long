/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:11:39 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/28 17:15:47 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	exit_window(t_win *window)
{
	write (1, "window closed\n", 15);
	if (window)
	{
		clean_map(window->map_ptr.map);
		if (window->imgs.ply_img)
			mlx_destroy_image(window->mlx_ptr, window->imgs.ply_img);
		if (window->imgs.floor_img)
			mlx_destroy_image(window->mlx_ptr, window->imgs.floor_img);
		if (window->imgs.exit_img)
			mlx_destroy_image(window->mlx_ptr, window->imgs.exit_img);
		if (window->imgs.item_img)
			mlx_destroy_image(window->mlx_ptr, window->imgs.item_img);
		if (window->imgs.wall_img)
			mlx_destroy_image(window->mlx_ptr, window->imgs.wall_img);
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	}
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(EXIT_SUCCESS);
}
