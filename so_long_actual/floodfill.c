/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:50:07 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/28 22:23:43 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Can be better because i can do it only one time
*/
void	flood_fill(t_floodfill *f, int x, int y)
{
	if (f->map[x][y] == '1')
		return ;
	if (f->target == 'C')
	{
		if (f->map[x][y] == 'C')
			f->total += 1;
		if (f->map[x][y] == 'E')
			return ;
	}
	if (f->target == 'E')
	{
		if (f->map[x][y] == 'E')
			f->total += 1;
	}
	f->map[x][y] = '1';
	flood_fill(f, x + 1, y);
	flood_fill(f, x - 1, y);
	flood_fill(f, x, y + 1);
	flood_fill(f, x, y - 1);
}

int	init_floodfill(t_win *win, char c, int n_items)
{
	t_floodfill	*f;
	char		**map;

	f = (t_floodfill *) malloc(sizeof(t_floodfill));
	if (!f)
		return (0);
	f->total = 0;
	f->target = c;
	map = create_map(win);
	if (!map)
		return (0);
	f->map = map;
	flood_fill(f, win->map_ptr.y_player, win->map_ptr.x_player);
	if (f->total != n_items)
	{
		free_map(f->map, win);
		free(f);
		return (0);
	}
	free_map(f->map, win);
	free(f);
	return (1);
}

char	**create_map(t_win *win)
{
	char	**map;
	int		i;

	i = -1;
	map = NULL;
	map = (char **)malloc(sizeof(char *) * (win->height + 1));
	if (!map)
		return (NULL);
	while (++i < win->height)
		map[i] = ft_strdup(win->map_ptr.map[i]);
	return (map);
}

void	free_map(char **map, t_win *win)
{
	int	i;

	i = -1;
	while (++i < win->height)
		free(map[i]);
	free(map);
}
