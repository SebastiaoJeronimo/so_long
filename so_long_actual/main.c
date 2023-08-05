/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:01:20 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/31 21:44:29 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_keyboard(int keycode, t_win *w)
{
	if (keycode == ESC)
		return (exit_window(w));
	if (keycode == W || keycode == A \
	|| keycode == S || keycode == D)
	{
		w->map_ptr.map[w->map_ptr.y_player][w->map_ptr.x_player] = 0;
		start_movement(keycode, w);
	}
	build_map(w);
	return (0);
}

void	initial_checks(int argc, int *fd, char **argv)
{
	int	size_map;
	int	dot_index;

	if (argc != 2)
	{
		(void) write (1, "wrong number of arguments\n", 27);
		exit(EXIT_FAILURE);
	}
	size_map = ft_special_strlen(argv[1]);
	dot_index = size_map - 1 - 3;
	if (!(size_map >= 5 && ft_strncmp(argv[dot_index], ".ber", 4) \
		&& (indchr(argv[1], '.') == dot_index)))
	{
		(void) write (1, "please add a .ber map\n", 23);
		exit(EXIT_FAILURE);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd <= 0)
	{
		(void) write (1, "file is missing\n", 17);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	static t_win	window;
	int				fd;

	initial_checks(argc, &fd, argv);
	window.map_ptr.map = ft_create_map(window.map_ptr.map, fd, 0);
	if (!check_map(&window))
	{
		str_arr_free(&window);
		exit(0);
	}
	close(fd);
	window_init(&window);
	setup_images(&window);
	if (!window.mlx_ptr || !window.win_ptr)
		return (1);
	build_map(&window);
	mlx_key_hook(window.win_ptr, check_keyboard, &window);
	mlx_hook(window.win_ptr, 17, 0, exit_window, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
