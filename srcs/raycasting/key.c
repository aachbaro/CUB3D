/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:54:04 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/06 16:17:15 by aachbaro         ###   ########.fr       */
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
		clean_exit(data, 0);
	return (0);
}

int	destroy_win(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}
