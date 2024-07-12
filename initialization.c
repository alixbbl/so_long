/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:39:05 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/24 17:08:50 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_data(t_data *data)
{
	data->map.player = 0;
	data->map.sushi = 0;
	data->map.exit = 0;
	data->count_steps = 0;
	data->count_sushis = 0;
	data->count_player = 0;
	data->game_is_over = 0;
	data->new_x = 0;
	data->new_y = 0;
	data->img.empty = NULL;
	data->img.exit = NULL;
	data->img.wall = NULL;
	data->img.sushi = NULL;
	data->img.player = NULL;
	data->img.fox_on_door = NULL;
	data->game_is_over = 0;
	data->img.height = IMG_SIZ;
	data->img.width = IMG_SIZ;
	data->win_width = IMG_SIZ * data->map.lines;
	data->win_height = IMG_SIZ * data->map.columns;
}

void	init_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.map_ber[y])
	{
		while (data->map.map_ber[y][x])
		{
			if (data->map.map_ber[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_error_2("Error MLX ptr.\n", data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_height,
			data->win_width, "Let's play!");
	if (data->win_ptr == NULL)
	{
		ft_error_wind("Error Window ptr.\n", data);
	}
}

int	count_map_elements(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.map_ber[y])
	{
		while (data->map.map_ber[y][x] && data->map.map_ber[y][x] != '\n')
		{
			if (data->map.map_ber[y][x] == SUSHI)
				data->map.sushi++;
			if (data->map.map_ber[y][x] == EXIT)
				data->map.exit++;
			if (data->map.map_ber[y][x] == PLAYER)
				data->map.player++;
			x++;
		}
		x = 0;
		y++;
	}
	if ((data->map.sushi < 1) || (data->map.exit != 1)
		|| (data->map.player != 1))
		return (0);
	return (1);
}

void	init_images(t_data *data)
{
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, "door.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.exit)
		ft_error("Creating exit image failed.\n", data);
	data->img.empty = mlx_xpm_file_to_image(data->mlx_ptr, "grass.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.empty)
		ft_error("Creating grass image failed.\n", data);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, "wall.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.wall)
		ft_error("Creating wall image failed.\n", data);
	data->img.player = mlx_xpm_file_to_image(data->mlx_ptr, "fox_still.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.player)
		ft_error("Creating player image failed.\n", data);
	data->img.sushi = mlx_xpm_file_to_image(data->mlx_ptr, "sushi.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.sushi)
		ft_error("Creating sushi image failed.\n", data);
	data->img.fox_on_door = mlx_xpm_file_to_image(data->mlx_ptr,
			"fox_on_door.xpm", &data->img.width, &data->img.height);
	if (!data->img.fox_on_door)
		ft_error("Creating fox on door image failed.\n", data);
}
