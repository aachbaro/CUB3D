/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:25:00 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/06 16:36:27 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		print_square(t_img *img, int squa_size, t_pos coord, int color)
{
	int	i;
	int	j;

	j = 0;
	coord.x = coord.x * squa_size + 10;
	coord.y = coord.y * squa_size + 10;
	while (j < squa_size)
	{
		i = 0;
		coord.x -= squa_size;
		while (i < squa_size)
		{
			img->addr[coord.y * img->line_len
				/ 4 + coord.x + 10] = color;
			coord.x++;
			i++;
		}
		j++;
		coord.y++;
	}
	return (squa_size);
}

int		color_set(char c)
{
	if (c == '1')
		return (rgb_trad(0, 0, 0));
	else if (c == '0')
		return (rgb_trad(255, 255, 255));
	else
		return (rgb_trad(0, 0, 0));
}

void	render_minimap(t_data *data)
{
	t_pos	coord;
	t_pos	player;
	int	squa_size;
	int	color;

	squa_size = 10;
	player.x = (int)data->ray.pos_x;
	player.y = (int)data->ray.pos_y;
	coord.y = 0;
	while (data->info.map[coord.y])
	{
		coord.x = 0;
		while (data->info.map[coord.y][coord.x])
		{
			color = color_set(data->info.map[coord.y][coord.x]);
			print_square(&data->img, squa_size, coord, color);
			print_square(&data->img, squa_size, player, rgb_trad(1, 0, 0));
			coord.x++;
		}
		coord.y++;
	}
}
