/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:43:53 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/06 16:40:46 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_perpwalldist(t_ray *ray, int res_y)
{
	if (ray->side == 0)
		ray->perpwalldist = ((double)ray->map_x - ray->pos_x
				+ (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = ((double)ray->map_y - ray->pos_y
				+ (1 - ray->step_y) / 2) / ray->raydir_y;
	ray->lineh = (int)(res_y / ray->perpwalldist);
	ray->drawstart = -ray->lineh / 2 + res_y / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineh / 2 + res_y / 2;
	if (ray->drawend >= res_y)
		ray->drawend = res_y - 1;
}

void	draw_col(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ray.drawstart - 1)
	{
		data->img.addr[i * data->img.line_len
			/ 4 + data->ray.x] = data->info.ceil_color;
		i++;
	}
	draw_texture(data, data->ray.x, i - 1);
	i = data->ray.drawend + 1;
	while (i < data->info.win_h)
	{
		data->img.addr[i * data->img.line_len
			/ 4 + data->ray.x] = data->info.floor_color;
		i++;
	}
}
