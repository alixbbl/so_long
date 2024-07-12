/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:48:52 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/06 15:21:44 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		destroy_display(data);
		free(data->mlx_ptr);
		if (data->map.map_ber)
			ft_free(data->map.map_ber);
		exit (0);
	}
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
	{
		if (move_player(data, key) == 1)
			ft_game_message(data);
		else if (!move_player(data, key))
		{
			data->game_is_over = 1;
			mlx_loop_end(data->mlx_ptr);
		}
	}
	return (0);
}

int	handle_resize(int win_width, int win_height, t_data *data)
{
	data->win_width = win_width;
	data->win_height = win_height;
	display_map(data);
	return (0);
}

int	handle_close_window_event(t_data *data)
{
	destroy_display(data);
	free(data->mlx_ptr);
	if (data->map.map_ber)
		ft_free(data->map.map_ber);
	exit (0);
}
