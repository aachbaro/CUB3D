/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:41:17 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/24 13:05:57 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	del_mapinfo(t_minfo *info)
{
	if (info->tex_n)
		free(info->tex_n);
	if (info->tex_s)
		free(info->tex_s);
	if (info->tex_w)
		free(info->tex_w);
	if (info->tex_e)
		free(info->tex_e);
	if (info->sprite)
		free(info->sprite);
	return (0);
}

int	del_strtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	check_mapinfo(t_minfo info)
{
	if (info.res_x == -1 || info.res_y == -1)
		return (error_spec(8));
	if (info.floor_r == -1 || info.floor_g == -1 || info.floor_b == -1)
		return (error_spec(8));
	if (info.ceil_r == -1 || info.ceil_g == -1 || info.ceil_b == -1)
		return (error_spec(8));
	if (!info.tex_n || !info.tex_s || !info.tex_w || !info.tex_e)
		return (error_spec(8));
	if (!info.sprite)
		return (error_spec(8));
	if (!info.pos.dir)
		return (error_spec(8));
	return (1);
}

int	check_comma(char *str)
{
	size_t	i;
	int		comma;

	i = 0;
	comma = 0;
	while (i <= ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (-1);
	return (1);
}
