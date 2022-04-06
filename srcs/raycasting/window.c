/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:36:25 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/06 16:35:02 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	render(t_data *data)
{
	raycasting(data);
	render_minimap(data);
	mlx_put_image_to_window(data->m_ptr, data->m_win,
		data->img.p_img, 0, 0);
	return (0);
}

int	window(t_data *data)
{
	data->m_ptr = mlx_init();
	if (!data->m_ptr)
		clean_exit(data, 15);
	data->m_win = mlx_new_window(data->m_ptr, data->info.win_w,
			data->info.win_h, "CUB3D");
	data->img.p_img = mlx_new_image(data->m_ptr, data->info.win_w,
			data->info.win_h);
	data->img.addr = (int *)mlx_get_data_addr(data->img.p_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (load_texture(data))
		clean_exit(data, 16);
	raycast_init(data);
	mlx_loop_hook(data->m_ptr, &render, data);
	mlx_hook(data->m_win, 2, (1L << 0), &key_press, data);
	mlx_hook(data->m_win, 3, (1L << 1), &key_release, data);
	mlx_hook(data->m_win, DestroyNotify, NoEventMask, &destroy_win, data);
	mlx_loop(data->m_ptr);
	free(data->m_ptr);
	return (0);
}
