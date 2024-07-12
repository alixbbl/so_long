/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:20:44 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/04 17:22:06 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	print_data(t_data *data)
{
	ft_printf("data->mlx_ptr: %p\n", data->mlx_ptr);
	ft_printf("data->win_ptr: %p\n", data->win_ptr);
	ft_printf("data->img.mlx_img: %p\n", data->img.mlx_img);
	ft_printf("data->img.addr: %p\n", data->img.addr);
	ft_printf("data->img.height: %d\n", data->img.height);
	ft_printf("data->img.width: %d\n", data->img.width);
	ft_printf("data->img.empty: %p\n", data->img.empty);
	ft_printf("data->img.wall: %p\n", data->img.wall);
	ft_printf("data->img.player: %p\n", data->img.player);
	ft_printf("data->img.collect: %p\n", data->img.sushi);
	ft_printf("data->img.exit: %p\n", data->img.exit);
	ft_printf("data->map.count_player: %d\n", data->map.player);
	ft_printf("data->map.sushis_map: %d\n", data->map.sushi);
	ft_printf("data->map.count_exit: %d\n", data->map.exit);
	ft_printf("data->map.map_ber: %p\n", data->map.map_ber);
	ft_printf("data->map.path: %s\n", data->map.link_path);
	ft_printf("data->map.lines: %d\n", data->map.lines);
	ft_printf("data->map.columns: %d\n", data->map.columns);
	ft_printf("data->map.fd: %d\n", data->map.fd);
	ft_printf("data->player_x: %d\n", data->player_x);
	ft_printf("data->player_y: %d\n", data->player_y);
	ft_printf("data->count_steps: %d\n", data->count_steps);
	ft_printf("data->count_sushis: %d\n", data->count_sushis);
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map_ber[i])
	{
		ft_printf("%d--%s--\n", i, data->map.map_ber[i]);
		i++;
	}
}

void	print_int_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map.lines)
	{
		while (x < data->map.columns)
		{
			ft_printf("%d", data->map_copy[y][x]);
			x++;
		}
		ft_printf("\n");
		x = 0;
		y++;
	}
}
