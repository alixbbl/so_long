/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:33:51 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/17 13:34:39 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **ag)
{
	t_data	data;

	if (ac == 2)
	{
		if (!check_extent(ag[1]))
			ft_error_3("MISSING .BER EXTENT\n");
		create_map(ag[1], &data);
		init_map_data(&data);
		init_player(&data);
		parsing(&data);
		init_window(&data);
		init_images(&data);
		maintain_loop(data);
	}
	return (0);
}
