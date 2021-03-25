/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:20:08 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/24 13:23:39 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	set_pos(t_minfo *info, int y, int x)
{
	info->pos.pos_x = x;
	info->pos.pos_y = y;
	info->pos.dir = info->map[y][x];
	info->map[y][x] = '0';
	return (1);
}

int	error_spec(int n)
{
	ft_putstr_fd("Error\n", 1);
	if (n == 0)
		ft_putstr_fd("Invalid texture line\n", 1);
	if (n == 1)
		ft_putstr_fd("Texture found twice\n", 1);
	if (n == 2)
		ft_putstr_fd("Invalid RGB definition\n", 1);
	if (n == 3)
		ft_putstr_fd("Invalid line after map definition\n", 1);
	if (n == 4)
		ft_putstr_fd("Malloc failed\n", 1);
	if (n == 5)
		ft_putstr_fd("Map not closed\n", 1);
	if (n == 6)
		ft_putstr_fd("Initial position found twice\n", 1);
	if (n == 7)
		ft_putstr_fd("Open failed\n", 1);
	if (n == 8)
		ft_putstr_fd("Information missing", 1);
	return (-1);
}
