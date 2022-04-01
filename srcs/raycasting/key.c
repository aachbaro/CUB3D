/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:54:04 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 15:20:18 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

#include "../../cub3d.h"

int	key_press(int keysym, t_data *data)
{
	if (keysym == K_W)
		data->move.forward = 1;
	else if (keysym == K_S)
		data->move.back = 1;
	else if (keysym == K_A)
		data->move.left = 1;
	else if (keysym == K_D)
		data->move.right = 1;
	else if (keysym == K_LEFT)
		data->move.rotate_left = 1;
	else if (keysym == K_RIGHT)
		data->move.rotate_right = 1;
	return (0);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == K_W)
		data->move.forward = 0;
	else if (keysym == K_S)
		data->move.back = 0;
	else if (keysym == K_A)
		data->move.left = 0;
	else if (keysym == K_D)
		data->move.right = 0;
	else if (keysym == K_LEFT)
		data->move.rotate_left = 0;
	else if (keysym == K_RIGHT)
		data->move.rotate_right = 0;
	else if (keysym == K_ESCAPE)
	{
		mlx_destroy_image(data->m_ptr, data->img.p_img);
		mlx_destroy_window(data->m_ptr, data->m_win);
		mlx_destroy_display(data->m_ptr);
		free_all(data);
		exit(0);
	}
	return (0);
}
