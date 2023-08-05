/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:24:31 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/26 20:16:17 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Checks if the movement of the player to that specific tile is possible
 * @return 0 not possible 1 possible 2 possible and end the game
 * if the tile is a wall '1' returns 0 
 * if the tile is a floor '0' return 1
 * if the tile is a collectible return 1 (decrease colectible)
 * if the tile is a exit and you can get out return 2 else return 0
*/
int	check_movement(int x, int y, t_win *w)
{
	if (w->map_ptr.map[y][x] == '1')
		return (0);
	if (w->map_ptr.map[y][x] == 'E')
	{
		if (w->map_ptr.n_items == 0)
			return (2);
		return (0);
	}
	if (w->map_ptr.map[y][x] == 'C')
	{
		w->map_ptr.n_items--;
		return (1);
	}
	return (1);
}

void	exec_move(int new_x, int new_y, t_win *w)
{
	w->map_ptr.map[new_y][new_x] = 'P';
	w->map_ptr.map[w->map_ptr.y_player][w->map_ptr.x_player] = '0';
	w->map_ptr.x_player = new_x;
	w->map_ptr.y_player = new_y;
}

void	start_movement(int keycode, t_win *window)
{
	int	x;
	int	y;
	int	move_possible;

	x = window->map_ptr.x_player;
	y = window->map_ptr.y_player;
	if (keycode == W)
		y--;
	if (keycode == S)
		y++;
	if (keycode == A)
		x--;
	if (keycode == D)
		x++;
	move_possible = check_movement(x, y, window);
	if (move_possible > 0)
	{
		window->map_ptr.n_moves++;
		ft_putnbr_fd(window->map_ptr.n_moves, 1);
		write(1, "\n", 1);
		if (move_possible == 2)
			move_possible = exit_window(window);
		if (move_possible == 1)
			exec_move(x, y, window);
	}
}
