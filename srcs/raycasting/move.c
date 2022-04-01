/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:58:39 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 15:25:56 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_forward_back(t_ray *ray, char **map, t_data *data)
{
	if (data->move.forward == 1)
	{
		if (map[(int)ray->pos_y][(int)(ray->pos_x
			+ ray->dir_x * (data->move.speed * 2))] == '0')
			ray->pos_x += ray->dir_x * data->move.speed;
		if (map[(int)(ray->pos_y + ray->dir_y
				* (data->move.speed
					* 2))][(int)(ray->pos_x)] == '0')
			ray->pos_y += ray->dir_y * data->move.speed;
	}
	if (data->move.back == 1)
	{
		if (map[(int)(ray->pos_y)][(int)(ray->pos_x
			- ray->dir_x * (data->move.speed * 2))] == '0')
			ray->pos_x -= ray->dir_x * data->move.speed;
		if (map[(int)(ray->pos_y - (ray->dir_y
					* data->move.speed
					* 2))][(int)(ray->pos_x)] == '0')
			ray->pos_y -= ray->dir_y * data->move.speed;
	}
}

void	move_left_right(t_ray *ray, char **map, t_data *data)
{
	if (data->move.right == 1)
	{
		if (map[(int)ray->pos_y][(int)(ray->pos_x
			+ ray->dir_y * (data->move.speed * 2))] == '0')
			ray->pos_x += ray->dir_y * data->move.speed;
		if (map[(int)(ray->pos_y - ray->dir_x
				* (data->move.speed * 2))][(int)ray->pos_x] == '0')
			ray->pos_y -= ray->dir_x * data->move.speed;
	}
	if (data->move.left == 1)
	{
		if (map[(int)ray->pos_y][(int)(ray->pos_x
			- ray->dir_y * (data->move.speed * 2))] == '0')
			ray->pos_x -= ray->dir_y * data->move.speed;
		if (map[(int)(ray->pos_y + ray->dir_x
				* (data->move.speed * 2))][(int)ray->pos_x] == '0')
			ray->pos_y += ray->dir_x * data->move.speed;
	}
}

void	rotate_right_left(t_data *data, t_ray *ray)
{
	double	oldplane_x;
	double	olddir_x;

	oldplane_x = ray->plane_x;
	olddir_x = ray->dir_x;
	if (data->move.rotate_right == 1)
	{
		ray->dir_x = ray->dir_x * cos(-data->move.rotation / 2)
			- ray->dir_y * sin(-data->move.rotation / 2);
		ray->dir_y = olddir_x * sin(-data->move.rotation / 2)
			+ ray->dir_y * cos(-data->move.rotation / 2);
		ray->plane_x = ray->plane_x * cos(-data->move.rotation / 2)
			- ray->plane_y * sin(-data->move.rotation / 2);
		ray->plane_y = oldplane_x * sin(-data->move.rotation / 2)
			+ ray->plane_y * cos(-data->move.rotation / 2);
	}
	rotate_left(data, ray, olddir_x);
}

void	rotate_left(t_data *data, t_ray *ray, double olddir_x)
{
	double	oldplanex;

	if (data->move.rotate_left == 1)
	{
		olddir_x = ray->dir_x;
		oldplanex = ray->plane_x;
		ray->dir_x = ray->dir_x * cos(data->move.rotation / 2)
			- ray->dir_y * sin(data->move.rotation / 2);
		ray->dir_y = olddir_x * sin(data->move.rotation / 2)
			+ ray->dir_y * cos(data->move.rotation / 2);
		ray->plane_x = ray->plane_x * cos(data->move.rotation / 2)
			- ray->plane_y * sin(data->move.rotation / 2);
		ray->plane_y = oldplanex * sin(data->move.rotation / 2)
			+ ray->plane_y * cos(data->move.rotation / 2);
	}
}
