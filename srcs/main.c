/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:11:08 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/04 16:42:58 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_all(&data);
	if (!open_file(ac, av, &data))
		if (!get_info(&data))
			window(&data);
	free_all(&data);
	ft_error(&data);
	return (0);
}
