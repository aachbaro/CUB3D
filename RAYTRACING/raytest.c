/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:14:37 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/25 14:51:26 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		window_setting(t_minfo info)
{
	void    *mlx;
	void    *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, info.res_x, info.res_y, "CUB3D");
	mlx_loop(mlx);
	return (0);
}
