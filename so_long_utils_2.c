/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:42:08 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/21 17:06:38 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

void	ft_free_int(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.lines)
	{
		free(data->map_copy[i]);
		i++;
	}
	free(data->map_copy);
}

void	set_window_size(t_data *data)
{
	data->win_height = data->map.lines * 64;
	data->win_width = data->map.columns * 64;
}

int	is_valid_move(t_data *data)
{
	char	next_position;

	next_position = data->map.map_ber[data->new_y][data->new_x];
	if (next_position == WALL)
		return (0);
	return (1);
}
