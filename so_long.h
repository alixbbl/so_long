/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:21:02 by alibourb          #+#    #+#             */
/*   Updated: 2023/03/01 11:27:54 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include "get_next_line.h"
# include "ft_printf.h"

# define MLX_ERROR 1
# define IMG_SIZ 64

# define WALL '1'
# define SUSHI 'C'
# define EMPTY '0'
# define EXIT 'E'
# define PLAYER 'P'
# define FOX_ON_DOOR 'F'

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		height;
	int		width;
	void	*empty;
	void	*wall;
	void	*player;
	void	*sushi;
	void	*exit;
	void	*fox_on_door;
}				t_img;

typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_map
{
	int		player;
	int		sushi;
	int		exit;
	char	**map_ber;
	char	*link_path;
	int		lines;
	int		columns;
	int		fd;
}				t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_map		map;
	int			*addr;
	int			win_height;
	int			win_width;
	int			player_x;
	int			player_y;
	int			new_x;
	int			new_y;
	int			count_player;
	int			count_steps;
	int			count_sushis;
	int			exit_x;
	int			exit_y;
	int			**map_copy;
	int			game_is_over;
}	t_data;

/*CREATE_MAP FROM INPUT*/
int		check_extent(char *arg_name);
int		dimension_map(char *filename);
int		copy_line_to_map(char *line_map, int lines, int columns, t_data *data);
void	put_input_to_map(int lines, int columns, t_data *data);
void	create_map(char *filename, t_data *data);

/*PARSING*/
int		full_map(t_data *data);
int		check_elements_map(t_data *data);
int		check_rect(t_data *data);
int		check_closed_map(t_data *data);
int		parsing(t_data *data);
int		count_map_elements(t_data *data);
int		explorer(t_data *data, int x, int y);
int		copy_int_map_1(t_data *data);
void	copy_int_map_2(t_data *data, int y);
int		explore_int_map(t_data *data);

/*INITIALIZATION AND DISPLAY*/
void	init_map_data(t_data *data);
void	init_player(t_data *data);
void	init_window(t_data *data);
void	init_images(t_data *data);
int		display_map(t_data *data);
void	put_empty_or_wall(t_data *data, int x, int y);
void	put_exit_or_sushi(t_data *data, int x, int y);
void	put_players(t_data *data, int x, int y);
void	destroy_display(t_data *data);

/*RENDER*/
void	set_window_size(t_data *data);
void	maintain_loop(t_data data);
int		handle_keypress(int keysym, t_data *data);
int		handle_close_window_event(t_data *data);
int		handle_resize(int win_width, int win_height, t_data *data);
int		is_valid_move(t_data *data);
int		move_player(t_data *data, int keyboard);
void	move_direction(t_data *data, int keyboard);
void	move_exit(t_data *data);
void	move_sushi(t_data *data);
void	move_your_fox(t_data *data);
void	move_else(t_data *data);

/*UTILS*/
int		ft_strlen(char *str);
void	ft_error(char *str, t_data *data);
void	ft_error_2(char *str, t_data *data);
void	ft_error_3(char *str);
void	ft_error_wind(char *message, t_data *data);
void	ft_putstr_fd(char *str, int fd);
void	ft_free(char **tab);
void	ft_free_int(t_data *data);
void	free_images(t_data *data);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	print_data(t_data *data);
void	print_map(t_data *data);
int		ft_game_message(t_data *data);
void	print_int_map(t_data *data);

#endif
