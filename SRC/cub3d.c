/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:42 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/29 16:54:44 by aachbaro         ###   ########.fr       */
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

void	print_info(t_minfo minfo)
{
	printf("Reso = %lld, %lld\n", minfo.res_x, minfo.res_y);
	printf("Floo = %d, %d, %d\n", minfo.floor_r, minfo.floor_g, minfo.floor_b);
	printf("Ceil = %d, %d, %d\n", minfo.ceil_r, minfo.ceil_g, minfo.ceil_b);
	printf("Nord = %s\nSout = %s\n", minfo.tex_n, minfo.tex_s);
	printf("West = %s\nEast = %s\n", minfo.tex_w, minfo.tex_e);
	printf("Spri = %s\n", minfo.sprite);
	printf("Ipos = %dx, %dy, %c",minfo.pos.pos_x,minfo.pos.pos_y,minfo.pos.dir);
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
		del_mapinfo(&minfo);
		printf("\nTest de LEAKS\n");
		system("leaks a.out | grep leaked\n");
		return (0);
	}
	window_setting(minfo);
	del_strtab(minfo.map);
	del_mapinfo(&minfo);
	close(fd);
	printf("\nTest de LEAKS\n");
	system("leaks a.out | grep leaked\n");
	return (0);
}
