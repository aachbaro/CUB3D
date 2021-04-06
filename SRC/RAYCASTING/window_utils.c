/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:19:44 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/06 16:01:46 by aachbaro         ###   ########.fr       */
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

void	ray_init(t_ray *ray, t_minfo info)
{
	ray->pos_x = info.pos.pos_x + 0.5;
	ray->pos_y = info.pos.pos_y + 0.5;
	printf("\nOK\n");
	if (info.pos.dir == 'N')
		ray->dir_x = -1;
	else if (info.pos.dir == 'S')
		ray->dir_x = 1;
	else
		ray->dir_x = 0;
	if (info.pos.dir == 'E')
		ray->dir_y = 1;
	else if (info.pos.dir == 'W')
		ray->dir_y = -1;
	else
		ray->dir_y = 0;
	if (info.pos.dir == 'N')
		ray->plane_y = 0.66;
	else if (info.pos.dir == 'S')
		ray->plane_y = -0.66;
	else
		ray->plane_y = 0;
	if (info.pos.dir == 'E')
		ray->plane_x = 0.66;
	else if (info.pos.dir == 'W')
		ray->plane_x = -0.66;
	else
		ray->dir_y = 0;
}
