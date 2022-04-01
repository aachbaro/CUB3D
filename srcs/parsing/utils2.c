/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:04:14 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 15:19:34 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	set_pos(t_data *data, int y, int x)
{
	data->info.pos_x = x;
	data->info.pos_y = y;
	data->info.dir = data->info.map[y][x];
	data->info.map[y][x] = '0';
	return (1);
}

int	check_border(char **tab, int x, int y)
{
	int	l;
	int	h;

	l = ft_strlen(tab[0]) - 1;
	h = tab_len(tab) - 1;
	if ((x == 0 || y == 0 || x == l || y == h) \
			&& get_pos(" 1", tab[y][x]) == -1)
		return (-1);
	return (1);
}

int	check_mspaces(char **tab, int x, int y)
{
	int	l;
	int	h;

	l = ft_strlen(tab[0]) - 1;
	h = tab_len(tab) - 1;
	if (y > 0 && x > 0 && get_pos(" 1", tab[y - 1][x - 1]) == -1)
		return (-1);
	if (y > 0 && get_pos(" 1", tab[y - 1][x]) == -1)
		return (-1);
	if (y > 0 && x < l && get_pos(" 1", tab[y - 1][x + 1]) == -1)
		return (-1);
	if (x > 0 && get_pos(" 1", tab[y][x - 1]) == -1)
		return (-1);
	if (x < l && get_pos(" 1", tab[y][x + 1]) == -1)
		return (-1);
	if (y < h && x > 0 && get_pos(" 1", tab[y + 1][x - 1]) == -1)
		return (-1);
	if (y < h && get_pos(" 1", tab[y + 1][x]) == -1)
		return (-1);
	if (y < h && x < l && get_pos(" 1", tab[y + 1][x + 1]) == -1)
		return (-1);
	return (1);
}
