/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:36:25 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 15:27:44 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render(t_data *data)
{
	raycasting(data);
	mlx_put_image_to_window(data->m_ptr, data->m_win,
		data->img.p_img, 0, 0);
	return (0);
}

int	window(t_data *data)
{
	data->m_ptr = mlx_init();
	data->m_win = mlx_new_window(data->m_ptr, data->info.win_w,
			data->info.win_h, "CUB3D");
	data->img.p_img = mlx_new_image(data->m_ptr, data->info.win_w,
			data->info.win_h);
	data->img.addr = mlx_get_data_addr(data->img.p_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	raycast_init(data);
	mlx_loop_hook(data->m_ptr, &render, data);
	mlx_hook(data->m_win, 2, (1L << 0), &key_press, data);
	mlx_hook(data->m_win, 3, (1L << 1), &key_release, data);
	mlx_loop(data->m_ptr);
	free(data->m_ptr);
	return (0);
}
