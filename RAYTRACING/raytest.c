/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:14:37 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/26 14:03:52 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
  char		*dst;

  dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
  *(unsigned int*)dst = color;
}

int		window_setting(t_minfo info)
{
	void    *mlx;
	void    *mlx_win;
//	t_data	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, info.res_x, info.res_y, "CUB3D");
//	mlx_loop(mlx);
//	img.img = mlx_new_image(mlx, 100, 100);
//	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	mlx_destroy_window(mlx, mlx_win);
//	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
