/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:15:32 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/24 13:09:28 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_res(char **line, t_minfo *info)
{
	if (check_res(line) == -1)
		return (-1);
	if (info->res_x == -1 || info->res_y == -1)
	{
		info->res_x = ft_ultratoi(line[1]);
		info->res_y = ft_ultratoi(line[2]);
	}
	else
		return (error_spec(1));
	return (1);
}

int	get_north(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->tex_n)
		info->tex_n = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}

int	get_south(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->tex_s)
		info->tex_s = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}

int	get_west(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->tex_w)
		info->tex_w = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}
