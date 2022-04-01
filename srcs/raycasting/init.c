/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:55:04 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 12:06:41 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	raycast_init(t_data *data)
{
	data->ray.pos_x = data->info.pos_x;
	data->ray.pos_y = data->info.pos_y;
	init_dirplane(data);
	init_move(data);
}

void	init_dirplane(t_data *data)
{
	if (data->info.dir == 'W')
		data->ray.dir_x = -1;
	else if (data->info.dir == 'E')
		data->ray.dir_x = 1;
	else
		data->ray.dir_x = 0;
	if (data->info.dir == 'S')
		data->ray.dir_y = 1;
	else if (data->info.dir == 'N')
		data->ray.dir_y = -1;
	else
		data->ray.dir_y = 0;
	if (data->info.dir == 'W')
		data->ray.plane_y = 0.66;
	else if (data->info.dir == 'E')
		data->ray.plane_y = -0.66;
	else
		data->ray.plane_y = 0;
	if (data->info.dir == 'S')
		data->ray.plane_x = 0.66;
	else if (data->info.dir == 'N')
		data->ray.plane_x = -0.66;
	else
		data->ray.plane_x = 0;
}

void	init_move(t_data *data)
{
	data->move.forward = 0;
	data->move.back = 0;
	data->move.left = 0;
	data->move.right = 0;
	data->move.rotate_left = 0;
	data->move.rotate_right = 0;
	data->move.speed = 0.15;
	data->move.rotation = 0.1;
}
