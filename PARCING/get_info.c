/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:19:27 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/23 15:49:00 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**get_indic_tab(void)
{
	char	**indic;

	indic = malloc(sizeof(char *) * 9);
	if (!indic)
		return (NULL);
	indic[0] = "R";
	indic[1] = "NO";
	indic[2] = "SO";
	indic[3] = "WE";
	indic[4] = "EA";
	indic[5] = "S";
	indic[6] = "F";
	indic[7] = "C";
	indic[8] = NULL;
	return (indic);
}

int		get_parcer_tab(int (***f)(char **, t_minfo *))
{
	(*f) = malloc(sizeof(*f) * 8);
	if (!(*f))
		return (-1);
	(*f)[0] = &get_res;
	(*f)[1] = &get_north;
	(*f)[2] = &get_south;
	(*f)[3] = &get_west;
	(*f)[4] = &get_east;
	(*f)[5] = &get_sprite;
	(*f)[6] = &get_floor;
	(*f)[7] = &get_ceil;
	return (1);
}

int		texture_parcing(char *line, t_minfo *map)
{
	char	**splited;
	int		(**f)(char **, t_minfo *);
	char	**indic;
	int		ret;

	if (line[0] == 0)
		return (1);
	ret = 1;
	splited = ft_split(line, ' ');
	get_parcer_tab(&f);
	if (!f)
		return (error_spec(4));
	indic = get_indic_tab();
	if (!indic)
		return (error_spec(4));
	if (get_pos_tab(splited[0], indic) != -1)
		ret = (f)[get_pos_tab(splited[0], indic)](splited, map);
	else
		ret = error_spec(0);
	free(indic);
	del_strtab(splited);
	free(f);
	return (ret);
}

int		get_info(int *fd, t_minfo *map, char *file)
{
	int		ret;
	int		error;
	char	*line;

	ret = 1;
	while (get_next_line(*fd, &line) && !is_map_line(line))
	{
		error = texture_parcing(line, map);
		free(line);
		if (error == -1)
			return (-1);
	}
	if (is_map_line(line))
	{
		map->map_x = ft_strlen(line);
		map->map_y++;
		free(line);
	}
	error = get_map(fd, &line, map, file);
	if (check_mapinfo(*map) == -1 || error == -1 || check_maptab(map) == -1)
		return (-1);
	return (0);
}
