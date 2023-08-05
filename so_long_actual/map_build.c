/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:12:04 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/03 20:09:35 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//alterei para int
int	build_map(t_win *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < window->height)
	{
		j = 0;
		while (j < window->width)
		{
			insert_image(window->map_ptr.map[i][j], j, i, window);
			j++;
		}
		i++;
	}
	return (1);
}

void	insert_image(char c, int i, int j, t_win *win)
{
	if (c == 'P')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->imgs.ply_img, i * PIXELS, j * PIXELS);
	if (c == 'C')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->imgs.item_img, i * PIXELS, j * PIXELS);
	if (c == 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->imgs.exit_img, i * PIXELS, j * PIXELS);
	if (c == '1')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->imgs.wall_img, i * PIXELS, j * PIXELS);
	if (c == '0')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->imgs.floor_img, i * PIXELS, j * PIXELS);
}

void	setup_images(t_win	*window)
{
	int	size;

	window->imgs.ply_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./capybara.xpm", &size, &size);
	window->imgs.exit_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./water.xpm", &size, &size);
	window->imgs.floor_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./relva.xpm", &size, &size);
	window->imgs.wall_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./pedra.xpm", &size, &size);
	window->imgs.item_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./guarana-lata.xpm", &size, &size);
	window->imgs.size = size;
}

/*typedef struct s_img
{
	void	*ply_img;
	void	*exit_img;
	void	*wall_img;
	void	*floor_img;
	void	*item_img
}		t_img;*/
