/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:15:00 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/14 11:53:16 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_message(t_data *data)
{
	ft_printf("Moves counter : %d\n", data->count_steps);
	return (1);
}

void	maintain_loop(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &display_map, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask,
		&handle_keypress, &data);
	mlx_hook(data.win_ptr, 33, 1L << 5, &handle_resize, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&handle_close_window_event, &data);
	mlx_loop(data.mlx_ptr);
}

void	destroy_display(t_data *data)
{
	free_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
}

void	free_images(t_data *data)
{
	if (data->img.empty)
		mlx_destroy_image(data->mlx_ptr, data->img.empty);
	if (data->img.wall)
		mlx_destroy_image(data->mlx_ptr, data->img.wall);
	if (data->img.sushi)
		mlx_destroy_image(data->mlx_ptr, data->img.sushi);
	if (data->img.exit)
		mlx_destroy_image(data->mlx_ptr, data->img.exit);
	if (data->img.player)
		mlx_destroy_image(data->mlx_ptr, data->img.player);
	if (data->img.fox_on_door)
		mlx_destroy_image(data->mlx_ptr, data->img.fox_on_door);
}

void	move_direction(t_data *data, int keyboard)
{
	data->new_x = data->player_x;
	data->new_y = data->player_y;
	if (keyboard == XK_w)
		data->new_y--;
	else if (keyboard == XK_a)
		data->new_x--;
	else if (keyboard == XK_s)
		data->new_y++;
	else if (keyboard == XK_d)
		data->new_x++;
}
