/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:49:25 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/24 11:47:34 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_east(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->tex_e)
		info->tex_e = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}

int	get_sprite(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->sprite)
		info->sprite = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}

int	check_rgb(char **rgb)
{
	int	i;
	int	j;

	j = 0;
	while (rgb[j])
	{
		i = 0;
		while (rgb[j][i])
		{
			if (ft_isdigit(rgb[j][i]) == 0)
				return (-1);
			i++;
		}
		if (ft_atoi(rgb[j]) < 0 || ft_atoi(rgb[j]) > 255)
			return (-1);
		j++;
	}
	if (j != 3)
		return (-1);
	return (1);
}

int	get_floor(char **line, t_minfo *info)
{
	char	**splited;

	if (tab_len(line) != 2 || check_comma(line[1]) == -1)
		return (error_spec(0));
	splited = ft_split(line[1], ',');
	if (check_rgb(splited) == -1)
	{
		del_strtab(splited);
		return (error_spec(2));
	}
	if (info->floor_r == -1 && info->floor_g == -1 && info->floor_b == -1)
	{
		info->floor_r = ft_atoi(splited[0]);
		info->floor_g = ft_atoi(splited[1]);
		info->floor_b = ft_atoi(splited[2]);
		del_strtab(splited);
	}
	else
	{
		del_strtab(splited);
		return (error_spec(1));
	}
	return (1);
}

int	get_ceil(char **line, t_minfo *info)
{
	char	**splited;

	if (tab_len(line) != 2 || check_comma(line[1]) == -1)
		return (error_spec(0));
	splited = ft_split(line[1], ',');
	if (check_rgb(splited) == -1)
	{
		del_strtab(splited);
		return (error_spec(2));
	}
	if (info->ceil_r == -1 && info->ceil_g == -1 && info->ceil_b == -1)
	{
		info->ceil_r = ft_atoi(splited[0]);
		info->ceil_g = ft_atoi(splited[1]);
		info->ceil_b = ft_atoi(splited[2]);
		del_strtab(splited);
	}
	else
	{
		del_strtab(splited);
		return (error_spec(1));
	}
	return (1);
}
