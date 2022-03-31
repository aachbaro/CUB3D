/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:56:24 by aachbaro          #+#    #+#             */
/*   Updated: 2022/03/31 18:25:17 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define K_ESCAPE 65307
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100

typedef struct	s_info
{
	int		win_w;
	int		win_h;
	int		floor_color;
	int		ceil_color;
	unsigned int	w_map;
	unsigned int	h_map;
	char		*n_tex;
	char		*s_tex;
	char		*e_tex;
	char		*w_tex;
	char		**map;
	int		pos_x;
	int		pos_y;
	char		dir;
}			t_info;

typedef struct		s_img
{
  void				*p_img;
  char				*addr;
  int				bpp;
  int				line_len;
  int				endian;
}					t_img;

typedef struct		s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			raydir_x;
	double			raydir_y;
	double			camera_x;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineh;
	int				drawstart;
	int				drawend;
	int				x;
}					t_ray;

typedef struct		s_move
{
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	double			speed;
	double			rotation;
}				t_move;

typedef struct		s_data
{
	void			*m_ptr;
	void			*m_win;
	t_img			img;
	t_info			info;
	t_ray			ray;
	t_move			move;
	int			fd;
	char			*file;
	int			error;
}				t_data;

void		init_all(t_data *data);
int		open_file(int ac, char **av, t_data *data);
void		ft_error(t_data *data);
void		ft_error2(t_data *data);
void		free_all(t_data *data);
int		is_map_line(char *line);
int		del_strtab(char **tab);
int		get_map_info(t_data *data, char *line);
int		send_with_id(t_data *data, char **split);
int		get_info(t_data *data);
int		check_info(t_data *data);
int		tab_len(char **tab);
int		get_texture(t_data *data, char **split);
int		get_floor(char **line, t_data *data);
int		get_ceil(char **line, t_data *data);
int		check_rgb(char **rgb);
int		rgb_trad(int r, int g, int b);
int		check_comma(char *str);
int		get_map(char **line, t_data *data);
int		get_map_size(char *line, t_data *data);
int		fill_mapline(char *line, t_data *data, int y);
int 		check_maptab(t_data *data);
int		set_pos(t_data *data, int y, int x);
int		check_border(char **tab, int x, int y);
int		check_mspaces(char **tab, int x, int y);
int		get_pos(char *str, char c);


#endif
