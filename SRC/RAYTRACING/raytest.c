/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:14:37 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/29 16:54:38 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
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

int	rgb_trad(int r, int g, int b)
{
	return (r * 65536 + g * 256 + b);
}

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_input(int keysym, t_mlxdt *data)
{
//	printf("\n%d\n", keysym);
	if (keysym == K_ESCAPE)
	{
		mlx_destroy_window(data->m_ptr, data->m_win);
		data->m_win = NULL;
		exit(1);
	}
	return (0);
}

int	render(t_mlxdt *data)
{
	int	i;
	int	j;

	j = 0;
	if (data->m_win != NULL)
	{
		while (j < 1080)
		{
			i = 0;
			while (i < 1920)
			{
				img_pix_put(&data->img, i, j, rgb_trad(255, 255, 255));
				i++;
			}
			j++;
		}
	}
	mlx_put_image_to_window(data->m_ptr, data->m_win, data->img.p_img, 0, 0);
	return (0);
}

int		window_setting(t_minfo info)
{
	t_mlxdt	data;

	/* init window & mlx_ptr */
	data.m_ptr = mlx_init();
	data.m_win = mlx_new_window(data.m_ptr, info.res_x, info.res_y, "CUB3D");

	/* init img */
	data.img.p_img = mlx_new_image(data.m_ptr, info.res_x, info.res_y);
	data.img.addr = mlx_get_data_addr(data.img.p_img, &data.img.bpp, 
			&data.img.line_len, &data.img.endian);

	/* loop def */
	mlx_loop_hook(data.m_ptr, &render, &data);
	mlx_key_hook(data.m_win, &handle_input, &data);
	mlx_loop(data.m_ptr);

//	mlx_destroy_display(mlx);
	free(data.m_ptr);
	return (0);
}
