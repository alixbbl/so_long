/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:21:00 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/14 11:52:08 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	copy_int_map_1(t_data *data)
{
	int	y;

	y = 0;
	data->map_copy = malloc(sizeof(int *) * data->map.lines);
	if (!data->map_copy)
		return (0);
	while (y < data->map.lines)
	{
		data->map_copy[y] = malloc(sizeof(int) * (data->map.columns));
		if (!data->map_copy[y])
		{
			while (--y >= 0)
				free(data->map_copy[y]);
			free(data->map_copy);
			data->map_copy = NULL;
			return (0);
		}
		copy_int_map_2(data, y);
		y++;
	}
	return (1);
}

void	copy_int_map_2(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->map.columns)
	{
		if (data->map.map_ber[y][x] == WALL)
			data->map_copy[y][x] = 1;
		else if (data->map.map_ber[y][x] == EXIT)
			data->map_copy[y][x] = 3;
		else
			data->map_copy[y][x] = 0;
		x++;
	}
}

int	explorer(t_data *data, int x, int y)
{
	if (data->map_copy[y][x] != 1)
	{
		if (data->map_copy[y][x] == 3)
			return (1);
		data->map_copy[y][x] = 1;
		if ((explorer(data, x, y - 1))
			|| (explorer(data, x, y + 1))
			|| (explorer(data, x + 1, y))
			|| (explorer(data, x - 1, y)))
			return (1);
		data->map_copy[y][x] = 1;
	}
	return (0);
}

int	explore_int_map(t_data *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (!copy_int_map_1(data))
		return (0);
	if (!explorer(data, x, y))
	{
		if (data->map_copy)
			ft_free_int(data);
		return (0);
	}
	if (data->map_copy)
		ft_free_int(data);
	return (1);
}
