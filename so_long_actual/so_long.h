/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:48:56 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/31 21:34:32 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "./.mlx_linux/mlx.h" in case it doesnt recognize the library
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"

//keyboard numbers
# define ESC  65307
# define UP 65362
# define RIGHT 65363
# define LEFT 65361
# define DOWN 65364

//movement keyboard numbers
# define W 119
# define A 97
# define S 115
# define D 100

//window managment
# define PIXELS 64

typedef struct s_node{
	int	row;
	int	col;
}			t_Node;

typedef struct s_queue{
	t_Node	*array;
	int		front;
	int		rear;
	int		capacity;
	int		size;
}			t_Queue;

//struct for the floodfill algorithm
typedef struct s_floodfill{
	char	**map;
	int		total;
	char	target;
}			t_floodfill;

//struct for the type of image
typedef struct s_img
{
	int		size;
	void	*ply_img;
	void	*exit_img;
	void	*wall_img;
	void	*floor_img;
	void	*item_img;
}			t_img;

typedef struct map

{
	char			**map;
	int				x_player;
	int				y_player;
	int				x_exit;
	int				y_exit;
	int				n_items;
	int				n_moves;
}			t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	t_map	map_ptr;
	t_img	imgs;
}		t_win; 

//exit.c
int		exit_window(t_win *window);
void	clean_map(char **map);

//inits.c
char	**ft_create_map(char **map, int fd, int count);
void	window_init(t_win *window);

//checker.c
int		check_map(t_win	*window);
int		map_is_rectangular(t_win	*window);
int		map_is_surrounded(t_win	*window);
int		map_has_components(t_win	*window);

//utils.c
int		ft_strlen(char *str);
int		ft_special_strlen(char *str);
void	str_arr_free(t_win *window);
int		is_invalid_char(char c);
char	*ft_strchr(const char *str, int c);

//utils2.c
void	*ft_memset(void *s, int c, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	print_number(int number, int fd);
char	*ft_strdup(char *src);

//map_build.c
int		build_map(t_win *window);
void	insert_image(char c, int i, int j, t_win *win);
void	setup_images(t_win	*window);

//movement.c
void	start_movement(int keycode, t_win *window);
int		check_movement(int x, int y, t_win *w);
void	exec_move(int new_x, int new_y, t_win *w);

//floodfill.c
void	flood_fill(t_floodfill *f, int x, int y);
int		init_floodfill(t_win *win, char c, int n_items);
char	**create_map(t_win *win);
void	free_map(char **map, t_win *win);

//utils3.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		indchr(char *str, int c);
#endif
