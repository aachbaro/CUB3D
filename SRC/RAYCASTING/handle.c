/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:31:17 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/31 14:19:21 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	handle_input(int keysym, t_mlxdt *data)
{
	if (keysym == K_ESCAPE)
	{
		mlx_destroy_window(data->m_ptr, data->m_win);
		data->m_win = NULL;
		exit(0);
	}
	return (0);
}
