/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:26:42 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/19 15:03:13 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_map_size(int *fd, char *line, t_minfo *info)
{
	while (get_next_line(*fd, &line) && is_map_line(line))
	{
		if (ft_strlen(line) > info->map_x)
			info->map_x = ft_strlen(line);
		info->map_y++;
		free(line);
	}
	if (!is_map_line(line))
	{
		while (get_next_line(*fd, &line))
		{
			if (line[0] != 0)
			{
				free(line);
				return (-1);
			}
			free(line);
		}
	}
	info->map = malloc(sizeof(char *) * info->map_y + 1);
	if (!info->map)
		return (-1);
	return (0);
}

int		fill_mapline(char *line, t_minfo *info, int y)
{
	unsigned int	i;

	i = 0;
	info->map[y] = malloc(sizeof(char) * info->map_x);
	if (!info->map[y])
	{
		printf("\nWTF\n");
		return (-1);
	}
	while (line[i])
	{
		info->map[y][i] = line[i];
		i++;
	}
	while (i < info->map_x)
	{
		info->map[y][i] = ' ';
		i++;
	}
	info->map[y][i] = 0;
	return (1);
}

int		get_map(int *fd, char **line, t_minfo *info, char *file)
{
	unsigned int	y;
	int				error;

	y = 0;
	error = 0;
	error = get_map_size(fd, *line, info);
	printf("\nmap-x = %d map-y = %d\n", info->map_x, info->map_y);
	if (error == -1)
		return (-1);
	close(*fd);
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (-1);
	while (get_next_line(*fd, line) && !is_map_line(*line))
		free(*line);
	error = fill_mapline(*line, info, y);
	y++;
	free(*line);
	while (get_next_line(*fd, line) && is_map_line(*line))
	{
		error = fill_mapline(*line, info, y);
		free(*line);
		if (error == -1)
			return (-1);
		printf("info->map[y] = |%s|, y = %d\n", info->map[y], y);
		y++;
	}
	info->map[y] = NULL;
	print_map(info);
	return (error);
}

