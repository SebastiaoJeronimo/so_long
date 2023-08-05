/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:51:33 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/30 00:24:22 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_create_map(char **map, int fd, int count)
{
	char	*str;

	str = get_next_line(fd);
	if (!str && count == 0)
	{
		write(1, "map is empty or invalid\n", 25);
		exit (0);
	}
	if (str)
		map = ft_create_map(map, fd, count + 1);
	if (!map && count != 0)
		map = malloc((count + 1) * (sizeof(char *)));
	map[count] = str;
	return (map);
}

void	window_init(t_win *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, \
	window->width * PIXELS, window->height * PIXELS, "capy adventure");
}
