/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:35:17 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/21 16:57:36 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *message, t_data *data)
{
	int	fd;

	fd = open("/dev/stderr", O_WRONLY);
	if (fd > 0)
	{
		ft_putstr_fd("ERROR\n", fd);
		ft_putstr_fd(message, fd);
		destroy_display(data);
		if (data->map.map_ber)
			ft_free(data->map.map_ber);
		free(data->mlx_ptr);
		exit(1);
	}
}

void	ft_error_2(char *message, t_data *data)
{
	int	fd;

	fd = open("/dev/stderr", O_WRONLY);
	if (fd > 0)
	{
		ft_putstr_fd("ERROR\n", fd);
		ft_putstr_fd(message, fd);
		if (data->map.map_ber)
			ft_free(data->map.map_ber);
		exit(1);
	}
}

void	ft_error_wind(char *message, t_data *data)
{
	int	fd;

	fd = open("/dev/stderr", O_WRONLY);
	if (fd > 0)
	{
		ft_putstr_fd("ERROR\n", fd);
		ft_putstr_fd(message, fd);
		if (data->map.map_ber)
			ft_free(data->map.map_ber);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
}

void	ft_error_3(char *message)
{
	int	fd;

	fd = open("/dev/stderr", O_WRONLY);
	if (fd > 0)
	{
		ft_putstr_fd("ERROR\n", fd);
		ft_putstr_fd(message, fd);
		exit(1);
	}
}
