/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:43:03 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 15:17:54 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	send_with_id(t_data *data, char **split)
{
	if (ft_strlen(split[0]) == 2 && (!ft_strncmp(split[0], "NO", 2)
			|| !ft_strncmp(split[0], "SO", 2)
			|| !ft_strncmp(split[0], "EA", 2)
			|| !ft_strncmp(split[0], "WE", 2)))
		return (get_texture(data, split));
	else if (ft_strlen(split[0]) == 1 && !ft_strncmp(split[0], "C", 1))
		return (get_ceil(split, data));
	else if (ft_strlen(split[0]) == 1 && !ft_strncmp(split[0], "F", 1))
		return (get_floor(split, data));
	else
		return (data->error = 5, -1);
}

int	get_map_info(t_data *data, char *line)
{
	char	**split;

	if (*line)
	{
		split = ft_split(line, ' ');
		if (!split)
			return (data->error = 4, -1);
		if (!tab_len(split))
		{
			del_strtab(split);
			return (0);
		}
		if (send_with_id(data, split))
		{
			del_strtab(split);
			return (-1);
		}
		del_strtab(split);
	}
	return (0);
}

int	get_texture(t_data *data, char **split)
{
	if (tab_len(split) != 2)
		return (data->error = 6, -1);
	if (!ft_strncmp(split[0], "NO", 2) && !data->info.n_tex)
		data->info.n_tex = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 2) && !data->info.s_tex)
		data->info.s_tex = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 2) && !data->info.e_tex)
		data->info.e_tex = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 2) && !data->info.w_tex)
		data->info.w_tex = ft_strdup(split[1]);
	else
		return (data->error = 7, -1);
	if (!ft_strncmp(split[0], "NO", 2) && !data->info.n_tex)
		return (data->error = 4, -1);
	else if (!ft_strncmp(split[0], "SO", 2) && !data->info.s_tex)
		return (data->error = 4, -1);
	else if (!ft_strncmp(split[0], "EA", 2) && !data->info.e_tex)
		return (data->error = 4, -1);
	else if (!ft_strncmp(split[0], "WE", 2) && !data->info.w_tex)
		return (data->error = 4, -1);
	return (0);
}

int	get_floor(char **line, t_data *data)
{
	char	**splited;

	if (tab_len(line) != 2 || check_comma(line[1]) == -1)
		return (data->error = 8, -1);
	splited = ft_split(line[1], ',');
	if (check_rgb(splited) == -1)
	{
		del_strtab(splited);
		return (data->error = 8, -1);
	}
	if (data->info.floor_color == -1)
	{
		data->info.floor_color = rgb_trad(ft_atoi(splited[0]),
				ft_atoi(splited[1]), ft_atoi(splited[2]));
		del_strtab(splited);
	}
	else
	{
		del_strtab(splited);
		return (data->error = 8, -1);
	}
	return (0);
}

int	get_ceil(char **line, t_data *data)
{
	char	**splited;

	if (tab_len(line) != 2 || check_comma(line[1]) == -1)
		return (data->error = 8, -1);
	splited = ft_split(line[1], ',');
	if (check_rgb(splited) == -1)
	{
		del_strtab(splited);
		return (data->error = 8, -1);
	}
	if (data->info.ceil_color == -1)
	{
		data->info.ceil_color = rgb_trad(ft_atoi(splited[0]),
				ft_atoi(splited[1]), ft_atoi(splited[2]));
		del_strtab(splited);
	}
	else
	{
		del_strtab(splited);
		return (data->error = 8, -1);
	}
	return (0);
}
