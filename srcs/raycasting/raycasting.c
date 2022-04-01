/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:14:31 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 14:27:58 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	raycasting(t_data *data)
{
	data->ray.x = 0;
	while (data->ray.x < data->info.win_w)
	{
		init_raycasting(data);
		init_delta(&data->ray);
		init_sidedist(&data->ray);
		inc_sidedist(&data->ray, data->info.map);
		get_perpwalldist(&data->ray, data->info.win_h);
		draw_col(*data);
		data->ray.x++;
	}
	move_forward_back(&data->ray, data->info.map, data);
	move_left_right(&data->ray, data->info.map, data);
	rotate_right_left(data, &data->ray);
}

void	init_raycasting(t_data *data)
{
	data->ray.camera_x = 2 * data->ray.x / (double)data->info.win_w - 1;
	data->ray.raydir_x = data->ray.dir_x + data->ray.plane_x *
		data->ray.camera_x;
	data->ray.raydir_y = data->ray.dir_y + data->ray.plane_y *
		data->ray.camera_x;
	data->ray.map_x = (int)data->ray.pos_x;
	data->ray.map_y = (int)data->ray.pos_y;
	data->ray.hit = 0;
}

void	init_delta(t_ray *ray)
{
	if (ray->raydir_y == 0)
		ray->deltadist_x = 0;
	else if (ray->raydir_x == 0)
		ray->deltadist_x = 1;
	else
		ray->deltadist_x = sqrt(1 + (ray->raydir_y * ray->raydir_y)
				/ (ray->raydir_x * ray->raydir_x));
	if (ray->raydir_x == 0)
		ray->deltadist_y = 0;
	else if (ray->raydir_y == 0)
		ray->deltadist_y = 1;
	else
		ray->deltadist_y = sqrt(1 + (ray->raydir_x * ray->raydir_x)
				/ (ray->raydir_y * ray->raydir_y));
}

void	init_sidedist(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ray->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->deltadist_y;
	}
}

void	inc_sidedist(t_ray *ray, char **map)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] > '0')
			ray->hit = 1;
	}
}
