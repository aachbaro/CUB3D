/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:59:36 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 15:17:12 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_map(char **line, t_data *data)
{
	unsigned int	y;

	y = 0;
	if (get_map_size(*line, data))
		return (-1);
	close(data->fd);
	data->fd = open(data->file, O_RDONLY);
	if (data->fd == -1)
		return (data->error = 3, -1);
	while (get_next_line(data->fd, line))
	{
		if (is_map_line(*line))
		{
			if (fill_mapline(*line, data, y))
				return (-1);
			y++;
		}
		free(*line);
	}
	data->info.map[y] = NULL;
	free(*line);
	return (0);
}

int	get_map_size(char *line, t_data *data)
{
	while (get_next_line(data->fd, &line) && is_map_line(line))
	{
		if (ft_strlen(line) > data->info.w_map)
			data->info.w_map = ft_strlen(line);
		data->info.h_map++;
		free(line);
	}
	if (!is_map_line(line))
	{
		free(line);
		while (get_next_line(data->fd, &line))
		{
			if (line[0] != 0)
			{
				free(line);
				return (data->error = 10, -1);
			}
			free(line);
		}
	}
	free(line);
	data->info.map = malloc(sizeof(char *) * (data->info.h_map + 1));
	if (!data->info.map)
		return (data->error = 4, -1);
	return (0);
}

int	fill_mapline(char *line, t_data *data, int y)
{
	unsigned int	i;

	i = 0;
	data->info.map[y] = malloc(sizeof(char) * data->info.w_map + 1);
	if (!data->info.map[y])
		return (data->error = 4, -1);
	while (line[i])
	{
		data->info.map[y][i] = line[i];
		i++;
	}
	while (i < data->info.w_map)
	{
		data->info.map[y][i] = ' ';
		i++;
	}
	data->info.map[y][i] = 0;
	return (0);
}

int	check_maptab(t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (data->info.map[j])
	{
		i = 0;
		while (data->info.map[j][i])
		{
			if (check_border(data->info.map, i, j) == -1
				|| (data->info.map[j][i] == ' '
				&& check_mspaces(data->info.map, i, j) == -1))
				return (data->error = 11, -1);
			if (get_pos("NESW", data->info.map[j][i]) != -1
				&& !data->info.dir)
				set_pos(data, j, i);
			else if (get_pos("NESW", data->info.map[j][i]) != -1
				&& data->info.dir)
				return (data->error = 12, -1);
			i++;
		}
		j++;
	}
	return (0);
}
