/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:19:14 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/06 17:13:42 by aachbaro         ###   ########.fr       */
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
		if (map[ray->map_y][ray->map_x] > '0')
			ray->hit = 1;
	}
}

void	get_perpwalldist(t_ray *ray)
{
//	printf("\n%d | %f | %d | %f", ray->map_x, ray->pos_x, ray->step_x, ray->raydir_x);
	if (ray->side == 0)
		ray->perpwalldist = fabs((ray->map_x - ray->pos_x + (1 - ray->step_x) / 2)
			/ ray->raydir_x);
	else
		ray->perpwalldist = fabs((ray->map_y - ray->pos_y + (1 - ray->step_y) / 2)
			/ ray->raydir_y);
}

void	draw_col(t_mlxdt data)
{
	int	i;

	i = 0;
//	printf("|ds = %d||de = %d|", data.ray.drawstart, data.ray.drawend);
	while (i < data.ray.drawstart)
	{
		img_pix_put(&data.img, data.ray.x, i, data.info->ceil_color);
		i++;
	}
	while (i < data.ray.drawend)
	{
		if (data.ray.side == 1)
			img_pix_put(&data.img, data.ray.x, i, rgb_trad(127, 0, 0));
		else
			img_pix_put(&data.img, data.ray.x, i, rgb_trad(255, 0, 0));
		i++;
	}
	while (i < data.info->res_y)
	{
		img_pix_put(&data.img, data.ray.x, i, data.info->floor_color);
		i++;
	}
}

void	render_raycast(t_mlxdt *data)
{
	data->ray.x = 0;
	while (data->ray.x < data->info->res_x)
	{
	//	printf("\n\n ---- STEP %d ----\n", data->ray.x);
		data->ray.camera_x = 2 * data->ray.x / (double)data->info->res_x - 1;
		data->ray.raydir_x = data->ray.dir_x + data->ray.plane_x *
			data->ray.camera_x;
		data->ray.raydir_y = data->ray.dir_y + data->ray.plane_y *
			data->ray.camera_x;
	//	printf("\nraydirX = %f, raydirY = %f, cameraX = %f", data->ray.raydir_x, data->ray.raydir_y, data->ray.camera_x);
		data->ray.map_x = (int)data->ray.pos_x;
		data->ray.map_y = (int)data->ray.pos_y;
	//	printf("\nmapX = %d, mapY = %d", data->ray.map_x, data->ray.map_y);
		init_delta(&data->ray);
	//	printf("\ndeltadistX = %f, deltadistY = %f", data->ray.deltadist_x, data->ray.deltadist_y);
		data->ray.hit = 0;
		init_step(&data->ray);
	//	printf("\nstepX = %d, stepY = %d, sidedistX = %f, sidedistY = %f", data->ray.step_x, data->ray.step_y, data->ray.sidedist_x, data->ray.sidedist_y);
		inc_sidedist(&data->ray, data->info->map);
	//	printf("\nsidedistX = %f, sidedistY = %f, mapX = %d, mapY = %d", data->ray.sidedist_x, data->ray.sidedist_y, data->ray.map_x, data->ray.map_y);
		get_perpwalldist(&data->ray);
	//	printf("\nperpwalldist = %f", data->ray.perpwalldist);
		data->ray.lineh = (int)(data->info->res_y / data->ray.perpwalldist);
		data->ray.drawstart = -(data->ray.lineh) / 2 + data->info->res_y / 2;
		if (data->ray.drawstart < 0)
			data->ray.drawstart = 0;
		data->ray.drawend = data->ray.lineh / 2 + data->info->res_y / 2;
		if (data->ray.drawend >= data->info->res_y)
			data->ray.drawend = data->info->res_y - 1;
	//	printf("\ndrawstart = %d, drawend = %d, lineh = %d", data->ray.drawstart, data->ray.drawend, data->ray.lineh);
		draw_col(*data);
		data->ray.x++;
//		if (data->ray.x == data->info->res_x)
//			exit(0);
	}
}
