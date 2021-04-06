/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:12:06 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/05 16:19:09 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_delta(t_ray *ray)
{
	if (ray->raydir_y == 0)
		ray->deltadist_x = 0;
	else if (ray->raydir_x == 0)
		ray->deltadist_x = 1;
	else
		ray->deltadist_x = sqrt(1 + (ray->raydir_y * ray->raydir_y)
			   	/ (ray->raydir_x * ray->raydir_x));
	if (ray->raydir_x == 0)
		ray->deltadist_y = 0;
	else if (ray->raydir_y == 0)
		ray->deltadist_y = 1;
	else
		ray->deltadist_y = sqrt(1 + (ray->raydir_x * ray->raydir_x)
			   / (ray->raydir_y * ray->raydir_y));
}
