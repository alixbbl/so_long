/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:30:51 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/24 17:07:36 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extent(char *arg_name)
{
	int	i;

	i = 0;
	while (arg_name[i])
		i++;
	i--;
	if (arg_name[i] == 'r')
	{
		i--;
		if (arg_name[i] == 'e')
		{
			i--;
			if (arg_name[i] == 'b')
				return (1);
		}
	}
	return (0);
}

int	dimension_map(char *filename)
{
	int		line_count;
	int		fd;
	char	*line;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close (fd);
	}
	return (line_count);
}

void	put_input_to_map(int lines, int columns, t_data *data)
{
	char	*line_map;

	line_map = get_next_line(data->map.fd);
	while (line_map != NULL)
	{
		if (!copy_line_to_map(line_map, lines, columns, data))
		{
			ft_free(data->map.map_ber);
			return ;
		}
		lines++;
		columns = 0;
		free(line_map);
		line_map = get_next_line(data->map.fd);
	}
	data->map.map_ber[lines] = NULL;
}

int	copy_line_to_map(char *line_map, int lines, int columns, t_data *data)
{
	data->map.map_ber[lines] = ft_calloc(ft_strlen(line_map) + 1, sizeof(char));
	if (data->map.map_ber[lines] == NULL)
	{
		free(line_map);
		ft_error_2("----Allocation failed----.\n", data);
		return (0);
	}
	while (line_map[columns] != '\0' && line_map[columns] != '\n')
	{
		data->map.map_ber[lines][columns] = line_map[columns];
		columns++;
	}
	data->map.columns = columns;
	data->map.map_ber[lines][columns] = '\0';
	return (1);
}

void	create_map(char *filename, t_data *data)
{
	int		columns;
	int		lines;

	columns = 0;
	lines = 0;
	data->map.lines = dimension_map(filename);
	data->map.link_path = filename;
	data->map.map_ber = ft_calloc(data->map.lines + 1, sizeof(char *));
	if (!data->map.map_ber)
	{
		ft_error_2("----Map allocation failed.----\n", data);
		return ;
	}
	data->map.fd = open(filename, O_RDONLY);
	if (data->map.fd < 0)
		ft_error_2("----Wrong map reading.----\n", data);
	else
	{
		put_input_to_map(lines, columns, data);
		close(data->map.fd);
	}
}
