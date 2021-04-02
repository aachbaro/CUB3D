/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:19:14 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/02 16:31:52 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_step(t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
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
		if (map[ray->map_y][ray->map_x] > 0)
			ray->hit = 1;
	}
}

void	get_perpwalldist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - ray->pos_x + (1 - ray->step_x) / 2)
			/ ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - ray->pos_y + (1 - ray->step_y) / 2)
			/ ray->raydir_y;
}

void	draw_col(t_mlxdt data)
{
	int	i;

	i = 0;
	while (i < data.ray->drawstart)
	{
		img_pix_put(&data.img, data.ray->x, i, data.info->ceil_color);
		i++;
	}
	while (i < data.ray->drawstart)
	{
		if (data.ray->side == 1)
			img_pix_put(&data.img, data.ray->x, i, rgb_trad(0, 0, 127));
		else
			img_pix_put(&data.img, data.ray->x, i, rgb_trad(0, 0, 255));
		i++;
	}
	while (i < data.info->res_y)
	{
		img_pix_put(&data.img, data.ray->x, i, data.info->floor_color);
		i++;
	}
}

void	render_raycast(t_mlxdt *data)
{
	data->ray->x = 0;
	while (data->ray->x < data->info->res_x)
	{
		printf("\nOK\n");
		data->ray->camera_x = 2 * data->ray->x / (double)data->info->res_x - 1;
		data->ray->raydir_x = data->ray->dir_x + data->ray->plane_x *
			data->ray->camera_x;
		data->ray->raydir_y = data->ray->dir_y + data->ray->plane_y *
			data->ray->camera_x;
		data->ray->map_x = (int)data->ray->pos_x;
		data->ray->map_y = (int)data->ray->pos_y;
		data->ray->deltadist_x = fabs(1 / data->ray->dir_x);
		data->ray->deltadist_y = fabs(1 / data->ray->dir_y);
		data->ray->hit = 0;
		init_step(data->ray);
		inc_sidedist(data->ray, data->info->map);
		get_perpwalldist(data->ray);
		data->ray->lineh = (int)(data->info->res_y / data->ray->perpwalldist);
		data->ray->drawstart = -(data->ray->lineh) / 2 + data->info->res_y / 2;
		if (data->ray->drawstart < 0)
			data->ray->drawstart = 0;
		data->ray->drawend = data->ray->lineh / 2 + data->info->res_y / 2;
		if (data->ray->drawstart >= data->info->res_y)
			data->ray->drawend = data->info->res_y - 1;
		draw_col(*data);
		data->ray->x++;
	}
}
