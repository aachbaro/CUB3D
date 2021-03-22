/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:08:58 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/22 15:35:35 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_pos_tab(char *str, char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (!(ft_strncmp(tab[i], str, ft_strlen(str) + 1)))
			return (i);
		i++;
	}
	return (-1);
}

int		tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (get_pos(" 012NSEW", line[i]) == -1)
			return (0);
		i++;
	}
	if (ft_strlen(line) == 0)
		return (0);
	return (1);
}

int		get_pos(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

void	set_minfo(t_minfo *minfo)
{
	minfo->res_x = -1;
	minfo->res_y = -1;
	minfo->floor_R = -1;
	minfo->floor_G = -1;
	minfo->floor_B = -1;
	minfo->ceil_R = -1;
	minfo->ceil_G = -1;
	minfo->ceil_B = -1;
	minfo->map_x = 0;
	minfo->map_y = 0;
	minfo->tex_n = NULL;
	minfo->tex_s = NULL;
	minfo->tex_w = NULL;
	minfo->tex_e = NULL;
	minfo->sprite = NULL;
	minfo->pos.pos_x = -1;
	minfo->pos.pos_y = -1;
	minfo->pos.dir = 0;
}
