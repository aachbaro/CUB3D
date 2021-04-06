/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:31:17 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/06 17:49:47 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	handle_input(int keysym, t_mlxdt *data)
{
	double rotSpeed = 0.2;
//	printf("\n%d\n", keysym);
	if (keysym == K_ESCAPE)
	{
		mlx_destroy_window(data->m_ptr, data->m_win);
		data->m_win = NULL;
		exit(0);
	}
	else if (keysym == K_W)
	{
		data->ray.pos_x += data->ray.dir_x * 0.2;
		data->ray.pos_y += data->ray.dir_y * 0.2;
	}
	else if (keysym == K_S)
	{
		data->ray.pos_x -= data->ray.dir_x * 0.2;
		data->ray.pos_y -= data->ray.dir_y * 0.2;
	}
	else if (keysym == K_RIGHT)
	{
		double	oldDirX = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(-rotSpeed) - data->ray.dir_y * sin(-rotSpeed);
		data->ray.dir_y = oldDirX * sin(-rotSpeed) + data->ray.dir_y * cos(-rotSpeed);
		double oldPlaneX = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(-rotSpeed) - data->ray.plane_y * sin(-rotSpeed);
		data->ray.plane_y = oldPlaneX * sin(-rotSpeed) + data->ray.plane_y * cos(-rotSpeed);
	}
	else if (keysym == K_LEFT)
	{
		double	oldDirX = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(rotSpeed) - data->ray.dir_y * sin(rotSpeed);
		data->ray.dir_y = oldDirX * sin(rotSpeed) + data->ray.dir_y * cos(rotSpeed);
		double oldPlaneX = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(rotSpeed) - data->ray.plane_y * sin(rotSpeed);
		data->ray.plane_y = oldPlaneX * sin(rotSpeed) + data->ray.plane_y * cos(rotSpeed);
	}
	return (0);
}
