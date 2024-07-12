/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_or_lose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:59:52 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/11 19:40:19 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_exit(t_data *data)
{
	data->map.map_ber[data->player_y][data->player_x] = EMPTY;
	data->player_x = data->new_x;
	data->player_y = data->new_y;
	data->map.map_ber[data->new_y][data->new_x] = FOX_ON_DOOR;
	if (data->count_sushis == data->map.sushi)
		data->game_is_over = 1;
	if (data->game_is_over)
	{
		destroy_display(data);
		free(data->mlx_ptr);
		if (data->map.map_ber)
			ft_free(data->map.map_ber);
		exit (0);
	}
}

void	move_sushi(t_data *data)
{
	ft_printf("ONE MORE SUUUUUUUSHIIIIIII\n");
	data->count_sushis++;
	if (data->map.map_ber[data->player_y][data->player_x] == FOX_ON_DOOR)
	{
		data->map.map_ber[data->player_y][data->player_x] = EXIT;
		data->player_x = data->new_x;
		data->player_y = data->new_y;
		data->map.map_ber[data->new_y][data->new_x] = PLAYER;
	}
	else
	{
		data->map.map_ber[data->player_y][data->player_x] = EMPTY;
		data->player_x = data->new_x;
		data->player_y = data->new_y;
		data->map.map_ber[data->new_y][data->new_x] = PLAYER;
	}
}

void	move_your_fox(t_data *data)
{
	data->map.map_ber[data->player_y][data->player_x] = EXIT;
	data->player_x = data->new_x;
	data->player_y = data->new_y;
	data->map.map_ber[data->new_y][data->new_x] = PLAYER;
}

void	move_else(t_data *data)
{
	data->map.map_ber[data->player_y][data->player_x] = EMPTY;
	data->player_x = data->new_x;
	data->player_y = data->new_y;
	data->map.map_ber[data->new_y][data->new_x] = PLAYER;
}

int	move_player(t_data *data, int keyboard)
{
	move_direction(data, keyboard);
	if (is_valid_move(data))
	{
		data->count_steps++;
		if (data->map.map_ber[data->new_y][data->new_x] == EXIT)
			move_exit(data);
		else if (data->map.map_ber[data->new_y][data->new_x] == SUSHI)
			move_sushi(data);
		else if ((data->map.map_ber[data->new_y][data->new_x] == EMPTY)
		&& (data->map.map_ber[data->player_y][data->player_x] == FOX_ON_DOOR))
			move_your_fox(data);
		else
			move_else(data);
		display_map(data);
	}
	return (1);
}
