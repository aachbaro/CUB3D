/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:27:59 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/01 15:18:43 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_pos(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (get_pos(" 01NSEW", line[i]) == -1)
			return (0);
		i++;
	}
	if (ft_strlen(line) == 0)
		return (0);
	return (1);
}

int	check_rgb(char **rgb)
{
	int	i;
	int	j;

	j = 0;
	while (rgb[j])
	{
		i = 0;
		while (rgb[j][i])
		{
			if (ft_isdigit(rgb[j][i]) == 0)
				return (-1);
			i++;
		}
		if (ft_atoi(rgb[j]) < 0 || ft_atoi(rgb[j]) > 255)
			return (-1);
		j++;
	}
	if (j != 3)
		return (-1);
	return (1);
}

int	rgb_trad(int r, int g, int b)
{
	return (r * 65536 + g * 256 + b);
}

int	check_comma(char *str)
{
	size_t	i;
	int		comma;

	i = 0;
	comma = 0;
	while (i <= ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (-1);
	return (1);
}
