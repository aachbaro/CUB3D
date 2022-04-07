/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:58:08 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/07 14:56:58 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_all(t_data *data)
{
	if (data->info.n_tex)
		free(data->info.n_tex);
	if (data->info.s_tex)
		free(data->info.s_tex);
	if (data->info.e_tex)
		free(data->info.e_tex);
	if (data->info.w_tex)
		free(data->info.w_tex);
	if (data->info.map)
		del_strtab(data->info.map);
	if (data->m_ptr)
		free(data->m_ptr);
	if (data->file)
		free(data->file);
	close(data->fd);
}

int	del_strtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

void	ft_error(t_data *data)
{
	if (data->error == 1)
		ft_putstr_fd("Error\nWrong number of parameters\n", 1);
	else if (data->error == 2)
		ft_putstr_fd("Error\nWrong file name\n", 1);
	else if (data->error == 3)
		ft_putstr_fd("Error\nOpen failed\n", 1);
	else if (data->error == 4)
		ft_putstr_fd("Error\nMalloc failed\n", 1);
	else if (data->error == 5)
		ft_putstr_fd("Error\nInvalid identifier\n", 1);
	else if (data->error == 6)
		ft_putstr_fd("Error\nInvalid texture line\n", 1);
	else if (data->error == 7)
		ft_putstr_fd("Error\nTexture line found twice\n", 1);
	else if (data->error == 8)
		ft_putstr_fd("Error\nInvalid ceil or floor color line\n", 1);
	else if (data->error == 9)
		ft_putstr_fd("Error\nTexture or ceil/floor color missing\n", 1);
	else if (data->error == 10)
		ft_putstr_fd("Error\nFile must end with map definition\n", 1);
	ft_error2(data);
}

void	ft_error2(t_data *data)
{
	if (data->error == 11)
		ft_putstr_fd("Error\nInvalid map definition\n", 1);
	else if (data->error == 12)
		ft_putstr_fd("Error\nInitial position found twice\n", 1);
	else if (data->error == 13)
		ft_putstr_fd("Error\nInitial position not found\n", 1);
	else if (data->error == 14)
		ft_putstr_fd("Error\nMap not found\n", 1);
	else if (data->error == 15)
		ft_putstr_fd("Error\nFailed initialising minilibx\n", 1);
	else if (data->error == 16)
		ft_putstr_fd("Error\nFailed loading textures\n", 1);
}

void	clean_exit(t_data *data, int err)
{
	int	i;

	i = 0;
	data->error = err;
	ft_error(data);
	mlx_destroy_image(data->m_ptr, data->img.p_img);
	while (i < 4)
	{
		if (data->tex[i].p_img)
			mlx_destroy_image(data->m_ptr, data->tex[i].p_img);
		i++;
	}
	mlx_destroy_window(data->m_ptr, data->m_win);
	mlx_destroy_display(data->m_ptr);
	free_all(data);
	exit(0);
}
