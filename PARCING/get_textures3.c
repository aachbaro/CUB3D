/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:36:25 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/24 13:11:25 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

long long	ft_ultratoi(const char *str)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

int			check_res(char **line)
{
	int	i;

	i = 0;
	while (line[1][i])
	{
		if (!ft_isdigit(line[1][i]))
			return (error_spec(0));
		i++;
	}
	while (line[2][i])
	{
		if (!ft_isdigit(line[2][i]))
			return (error_spec(0));
		i++;
	}
	return (0);
}
