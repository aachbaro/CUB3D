/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:29:56 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 15:19:09 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_info(t_data *data)
{
	char	*line;

	line = NULL;
	while (get_next_line(data->fd, &line) && !is_map_line(line))
	{
		if (get_map_info(data, line))
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	if (is_map_line(line))
	{
		data->info.w_map = ft_strlen(line);
		data->info.h_map++;
	}
	free(line);
	if (get_map(&line, data) || check_maptab(data))
		return (-1);
	return (check_info(data));
}

int	check_info(t_data *data)
{
	if (!data->info.n_tex || !data->info.s_tex || !data->info.e_tex
		|| !data->info.w_tex)
		return (data->error = 9, -1);
	if (data->info.floor_color == -1 || data->info.ceil_color == -1)
		return (data->error = 9, -1);
	if (!data->info.dir)
		return (data->error = 13, -1);
	if (!data->info.map)
		return (data->error = 14, -1);
	return (0);
}
