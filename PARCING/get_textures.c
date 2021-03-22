/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:15:32 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/22 13:44:15 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_res(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 3)
		return (-1);
	while (line[1][i])
		if (!ft_isdigit(line[1][i++]))
			return (-1);
	i = 0;
	while (line[2][i])
		if (!ft_isdigit(line[1][i++]))
			return (-1);
	if (info->res_x == -1 || info->res_y == -1)
	{
		info->res_x = ft_atoi(line[1]);
		info->res_y = ft_atoi(line[2]);
	}
	else
		return (-1);
	return (1);
}

int	get_north(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (-1);
	if (!info->tex_n)
		info->tex_n = ft_strdup(line[1]);
	else
		return (-1);
	return (1);
}

int	get_south(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (-1);
	if (!info->tex_s)
		info->tex_s = ft_strdup(line[1]);
	else
		return (-1);
	return (1);
}

int	get_west(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (-1);
	if (!info->tex_w)
		info->tex_w = ft_strdup(line[1]);
	else
		return (-1);
	return (1);
}
