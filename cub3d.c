/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:42 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/19 15:03:35 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	print_map(t_minfo *minfo)
{
	int	i;

	i = 0;
	printf("\n");
	while (minfo->map[i])
	{
		printf("%-5d|%s|\n", i, minfo->map[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		error;
	t_minfo	minfo;

	error = 0;
	fd = 0;
	set_minfo(&minfo);
	fd = open(av[ac - 1], O_RDONLY);
	if (fd != -1)
		error = get_info(&fd, &minfo, av[ac - 1]);
	if (error == -1 || fd == -1)
	{
		ft_putstr_fd("\nERROR\n", 1);
		del_mapinfo(&minfo);
		printf("\nTest de LEAKS\n");
		system("leaks a.out | grep leaked\n");
		return (0);
	}
	printf("Reso = %d, %d\n", minfo.res_x, minfo.res_y);
	printf("Floo = %d, %d, %d\n", minfo.floor_R, minfo.floor_G, minfo.floor_B);
	printf("Ceil = %d, %d, %d\n", minfo.ceil_R, minfo.ceil_G, minfo.ceil_B);
	printf("Nord = %s\nSout = %s\n", minfo.tex_n, minfo.tex_s);
	printf("West = %s\nEast = %s\n", minfo.tex_w, minfo.tex_e);
	printf("Spri = %s\n", minfo.sprite);
	print_map(&minfo);
	del_strtab(minfo.map);
	del_mapinfo(&minfo);
	close(fd);
	printf("\nTest de LEAKS\n");
	system("leaks a.out | grep leaked\n");
	return (0);
}
