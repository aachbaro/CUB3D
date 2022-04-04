/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:47:29 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/04 16:18:55 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_texture_address(t_data *data)
{
	data->tex[0].addr = mlx_get_data_addr(data->tex[0].p_img,
			&data->tex[0].bpp, &data->tex[0].line_len,
			&data->tex[0].endian);
	data->tex[1].addr = mlx_get_data_addr(data->tex[1].p_img,
			&data->tex[1].bpp, &data->tex[1].line_len,
			&data->tex[1].endian);
	data->tex[2].addr = mlx_get_data_addr(data->tex[2].p_img,
			&data->tex[2].bpp, &data->tex[2].line_len,
			&data->tex[2].endian);
	data->tex[3].addr = mlx_get_data_addr(data->tex[3].p_img,
			&data->tex[3].bpp, &data->tex[3].line_len,
			&data->tex[3].endian);
}

int	load_texture(t_data *data)
{
	data->tex[0].p_img = mlx_xpm_file_to_image(data->m_ptr,
			data->info.n_tex, &data->tex[0].width,
			&data->tex[0].height);
	if (!data->tex[0].p_img)
		return (-1);
	data->tex[1].p_img = mlx_xpm_file_to_image(data->m_ptr,
			data->info.s_tex, &data->tex[1].width,
			&data->tex[1].height);
	if (!data->tex[1].p_img)
		return (-1);
	data->tex[2].p_img = mlx_xpm_file_to_image(data->m_ptr,
			data->info.e_tex, &data->tex[2].width,
			&data->tex[2].height);
	if (!data->tex[2].p_img)
		return (-1);
	data->tex[3].p_img = mlx_xpm_file_to_image(data->m_ptr,
			data->info.w_tex, &data->tex[3].width,
			&data->tex[3].height);
	if (!data->tex[3].p_img)
		return (-1);
	get_texture_address(data);
	return (0);
}

void	init_texture(t_data *data)
{
	if (data->ray.side == 0 && data->ray.raydir_x < 0)
		data->t.tex_dir = 0;
	if (data->ray.side == 0 && data->ray.raydir_x >= 0)
		data->t.tex_dir = 1;
	if (data->ray.side == 1 && data->ray.raydir_y < 0)
		data->t.tex_dir = 2;
	if (data->ray.side == 1 && data->ray.raydir_y >= 0)
		data->t.tex_dir = 3;
	if (data->ray.side == 0)
		data->t.wall_x = data->ray.pos_y + data->ray.perpwalldist \
						* data->ray.raydir_y;
	else
		data->t.wall_x = data->ray.pos_x + data->ray.perpwalldist \
						* data->ray.raydir_x;
	data->t.wall_x -= floor((data->t.wall_x));
}

void	draw_texture(t_data *data, int x, int y)
{
	y = data->ray.drawstart - 1;
	init_texture(data);
	data->t.step = 1.0 * data->tex[0].height / data->ray.lineh;
	data->t.x_tex = (int)(data->t.wall_x
			* (double)data->tex[data->t.tex_dir].width);
	if (data->ray.side == 0 && data->ray.raydir_x > 0)
		data->t.x_tex = data->tex[data->t.tex_dir].width -
			data->t.x_tex - 1;
	if (data->ray.side == 1 && data->ray.raydir_y < 0)
		data->t.x_tex = data->tex[data->t.tex_dir].width -
			data->t.x_tex - 1;
	data->t.texpos = (data->ray.drawstart - data->info.win_h / 2 +
			data->ray.lineh / 2) * data->t.step;
	while (y++ <= data->ray.drawend)
	{
		data->t.y_tex = (int)data->t.texpos &
			(data->tex[data->t.tex_dir].height - 1);
		data->t.texpos += data->t.step;
		if (y < data->info.win_h && x < data->info.win_w)
			data->img.addr[y * data->img.line_len / 4 + x] =
				data->tex[data->t.tex_dir].addr[data->t.y_tex *
					data->tex[data->t.tex_dir].line_len /
					4 + data->t.x_tex];
	}
}
