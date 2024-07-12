/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:05:31 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/17 13:38:50 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	full_map(t_data *data)
{
	int	width;
	int	height;

	width = ft_strlen(data->map.map_ber[0]);
	height = data->map.lines;
	if (!width || !height)
		return (0);
	return (1);
}

int	check_rect(t_data *data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (data->map.map_ber[0][i] != '\n'
		&& data->map.map_ber[0][i] != '\0')
		i++;
	while (data->map.map_ber[y])
	{
		x = 0;
		while ((data->map.map_ber[y][x] != '\0')
			&& (data->map.map_ber[y][x] != '\n'))
			x++;
		if (i != x)
			return (0);
		y++;
	}
	return (1);
}

int	check_closed_map(t_data *data)
{
	int	x;
	int	y;
	int	width;
	int	height;

	y = 0;
	width = ft_strlen(data->map.map_ber[0]);
	height = data->map.lines;
	while (y < height)
	{
		x = 0;
		if (data->map.map_ber[y][x] != WALL
			|| data->map.map_ber[y][width - 1] != WALL)
			return (0);
		y++;
	}
	x = 0;
	while (x < width)
	{
		if (data->map.map_ber[0][x] != WALL
			|| data->map.map_ber[height - 1][x] != WALL)
			return (0);
		x++;
	}
	return (1);
}

int	check_elements_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map_ber[y])
	{
		x = 0;
		while (data->map.map_ber[y][x])
		{
			if ((data->map.map_ber[y][x] != PLAYER)
				&& (data->map.map_ber[y][x] != WALL)
				&& (data->map.map_ber[y][x] != EMPTY)
				&& (data->map.map_ber[y][x] != EXIT)
				&& (data->map.map_ber[y][x] != SUSHI))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	parsing(t_data *data)
{
	if (!full_map(data))
		ft_error_2("---EMPTY MAP---\n", data);
	if (!check_rect(data))
		ft_error_2("---MAP IS NOT A RECTANGLE---\n", data);
	if (!check_closed_map(data))
		ft_error_2("---MAP IS NOT CLOSED---\n", data);
	if (!check_elements_map(data))
		ft_error_2("---UNAPPROVED MAP COMPONENT---\n", data);
	if (!count_map_elements(data))
		ft_error_2("---WRONG NUMBER OF MAP COMPONENTS---\n", data);
	if (!explore_int_map(data))
		ft_error_2("---MAP PATH ISSUE---\n", data);
	return (1);
}
