/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:44:28 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/31 18:11:02 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//pre: map != NULL
//checkar se o mapa nao e vazio ver se ja checko isso antes
int	check_map(t_win	*win)
{
	if (!map_is_rectangular(win))
		return (0);
	if (!map_is_surrounded(win))
		return (0);
	if (!map_has_components(win))
	{
		write (1, "you dont have the correct number of elements\n", 46);
		return (0);
	}
	write (1, "has the necessary elements\n", 28);
	if (!init_floodfill(win, 'C', win->map_ptr.n_items))
	{
		write(1, "cant reach items\n", 18);
		return (0);
	}
	write(1, "can reach items\n", 17);
	if (!init_floodfill(win, 'E', 1))
	{
		write(1, "cant reach exit\n", 17);
		return (0);
	}
	write(1, "can reach exit\n", 16);
	return (1);
}

int	map_is_rectangular(t_win	*window)
{
	int	i;

	i = 0;
	if (!ft_special_strlen(window->map_ptr.map[0]))
	{
		write(1, "map is invalid (remove empty lines before the map)", 51);
		return (0);
	}
	window->width = ft_special_strlen(window->map_ptr.map[0]);
	while (window->map_ptr.map[i] && window->map_ptr.map[i][0] != '\n')
	{
		if (ft_special_strlen(window->map_ptr.map[0]) != \
			ft_special_strlen(window->map_ptr.map[i]))
		{
			write (1, "Map is not rectangular.", 24);
			return (0);
		}
		i++;
	}
	write (1, "map_is_rectangular\n", 20); 
	window->height = i;
	return (i);
}

int	map_is_surrounded(t_win	*window)
{
	int	i;
	int	c_index;
	int	l_index;

	i = 0;
	c_index = window->width - 1;
	l_index = window->height - 1;
	while (i++ < c_index)
		if (window->map_ptr.map[0][i] != '1' || \
		window->map_ptr.map[l_index][i] != '1')
			return (0);
	while (l_index > -1)
	{
		if (window->map_ptr.map[l_index][0] != '1' || \
		window->map_ptr.map[l_index][c_index] != '1')
			return (0);
		l_index--;
	}
	write (1, "map is surrounded\n", 19);
	return (1);
}

int	aux_components(t_win *window, int i, int j)
{
	if (window->map_ptr.map[i][j] == 'P')
	{
		if ((window->map_ptr.x_player))
		{
			write(1, "please put only one player \n", 29);
			return (0);
		}
		window->map_ptr.x_player = j;
		window->map_ptr.y_player = i;
	}
	if (window->map_ptr.map[i][j] == 'E')
	{
		if (window->map_ptr.x_exit)
		{
			write(1, "please put only one exit\n", 26);
			return (0);
		}
		window->map_ptr.x_exit = j;
		window->map_ptr.y_exit = i;
	}
	if (window->map_ptr.map[i][j] == 'C')
		window->map_ptr.n_items++;
	return (1);
}

/*
* C -> Collectible
* E -> Exit
* P -> Player
* This fucntion checks if there is at least one of these elements in the map
* This function searches in the game matrix for the required elements
* If this function finds wrong characters it exits and warns
*/
int	map_has_components(t_win *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < window->height)
	{
		j = -1;
		while (++j < window->width)
		{
			if (is_invalid_char(window->map_ptr.map[i][j]))
				return (0);
			if (!aux_components(window, i, j))
				return (0);
		}
		i++;
	}
	if (window->map_ptr.n_items == 0)
	{
		write (1, "please put at least one collectible \n", 38);
		return (0);
	}
	return (window->map_ptr.n_items && window->map_ptr.x_exit \
			&& window->map_ptr.y_player);
}
