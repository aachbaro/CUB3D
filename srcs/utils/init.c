/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:21:05 by aachbaro          #+#    #+#             */
/*   Updated: 2022/03/31 17:35:15 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_all(t_data *data)
{
	data->m_ptr = NULL;
	data->m_win = NULL;
	data->info.win_w = 1000;
	data->info.win_h = 600;
	data->info.floor_color = -1;
	data->info.ceil_color = -1;
	data->info.w_map = 0;
	data->info.h_map = 0;
	data->info.n_tex = NULL;
	data->info.s_tex = NULL;
	data->info.e_tex = NULL;
	data->info.w_tex = NULL;
	data->info.map = NULL;
	data->info.pos_x = -1;
	data->info.pos_y = -1;
	data->error = 0;
	data->info.dir = 0;
	data->fd = -2;
	data->file = NULL;
}

int	open_file(int ac, char **av, t_data *data)
{
	if (ac != 2)
	{
		data->error = 1;
		return (-1);
	}
	if (ft_strlen(av[1]) < 4
		|| ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4))
	{
		data->error = 2;
		return (-1);
	}
	if (!data->error)
	{
		data->fd = open(av[1], O_RDONLY);
		if (data->fd == -1)
			return (data->error = 3, -1);
		data->file = ft_strdup(av[1]);
		if (!data->file)
			return (data->error = 4, -1);
		return (0);
	}
	return (-1);
}
