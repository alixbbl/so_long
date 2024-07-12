/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:00:44 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/05 14:25:58 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!data->win_ptr)
		return (0);
	set_window_size(data);
	while (data->map.map_ber[y])
	{
		while (data->map.map_ber[y][x]
			&& data->map.map_ber[y][x] != '\n')
		{
			put_empty_or_wall(data, x, y);
			put_exit_or_sushi(data, x, y);
			put_players(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	put_empty_or_wall(t_data *data, int x, int y)
{
	if (data->map.map_ber[y][x] == EMPTY)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.empty, x * IMG_SIZ, y * IMG_SIZ);
	else if (data->map.map_ber[y][x] == WALL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.wall, x * IMG_SIZ, y * IMG_SIZ);
}

void	put_exit_or_sushi(t_data *data, int x, int y)
{
	if (data->map.map_ber[y][x] == EXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.exit, x * IMG_SIZ, y * IMG_SIZ);
	else if (data->map.map_ber[y][x] == SUSHI)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.sushi, x * IMG_SIZ, y * IMG_SIZ);
}

void	put_players(t_data *data, int x, int y)
{
	if (data->map.map_ber[y][x] == PLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player, x * IMG_SIZ, y * IMG_SIZ);
	else if (data->map.map_ber[y][x] == FOX_ON_DOOR)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.fox_on_door, x * IMG_SIZ, y * IMG_SIZ);
}
