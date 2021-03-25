/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:10:03 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/25 14:49:34 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "USELIBFT/libft.h"
# include "USE_GNL/get_next_line.h"
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_inipos
{
	int				pos_x;
	int				pos_y;
	char			dir;
}					t_inipos;

typedef struct		s_minfo
{
	long long		res_x;
	long long		res_y;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				ceil_r;
	int				ceil_g;
	int				ceil_b;
	unsigned int	map_x;
	unsigned int	map_y;
	char			*tex_n;
	char			*tex_s;
	char			*tex_w;
	char			*tex_e;
	char			*sprite;
	char			**map;
	t_inipos		pos;
}					t_minfo;

long long			ft_ultratoi(const char *str);
void				print_map(t_minfo *minfo);
char				**get_indic_tab();
int					del_mapinfo(t_minfo *info);
int					check_mapinfo(t_minfo info);
int					set_pos(t_minfo *info, int y, int x);
int					check_comma(char *str);
int					check_maptab(t_minfo *info);
int					check_mspaces(char **tab, int x, int y);
int					check_border(char **tab, int x, int y);
int					del_strtab(char **tab);
int					get_parcer_tab(int (***f)(char **, t_minfo *));
int					texture_parcing(char *line, t_minfo *map);
int					get_info(int *fd, t_minfo *map, char *file);
int					get_res(char **line, t_minfo *info);
int					check_res(char **line);
int					get_north(char **line, t_minfo *info);
int					get_south(char **line, t_minfo *info);
int					get_west(char **line, t_minfo *info);
int					get_east(char **line, t_minfo *info);
int					get_sprite(char **line, t_minfo *info);
int					get_floor(char **line, t_minfo *info);
int					get_ceil(char **line, t_minfo *info);
int					get_pos_tab(char *str, char **tab);
int					get_map_size(int *fd, char *line, t_minfo *info);
int					fill_mapline(char *line, t_minfo *info, int y);
int					get_map(int *fd, char **line, \
		t_minfo *info, char *file);
int					tab_len(char **tab);
int					is_map_line(char *line);
void				set_minfo(t_minfo *minfo);
int					get_pos(char *str, char c);
int					error_spec(int n);
int					window_setting(t_minfo info);

#endif
