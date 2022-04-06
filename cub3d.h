/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:56:24 by aachbaro          #+#    #+#             */
/*   Updated: 2022/04/06 16:18:07 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
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

typedef struct s_info
{
	unsigned int	w_map;
	unsigned int	h_map;
	int		win_w;
	int		win_h;
	int	floor_color;
	int	ceil_color;
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
  int				*addr;
  int				bpp;
  int				line_len;
  int				endian;
  int				width;
  int				height;
}					t_img;

typedef struct		s_texture
{
	int		tex_dir;
	double		wall_x;
	int		x_tex;
	int		y_tex;
	double		step;
	double		texpos;
}			t_texture;

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
	t_img			tex[4];
	t_texture		t;
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
int		window(t_data *data);
void		raycast_init(t_data *data);
void		init_dirplane(t_data *data);
void		init_move(t_data *data);
void		raycasting(t_data *data);
void		init_raycasting(t_data *data);
void		init_delta(t_ray *ray);
void		init_sidedist(t_ray *ray);
void		inc_sidedist(t_ray *ray, char **map);
void		get_perpwalldist(t_ray *ray, int res_y);
void		draw_col(t_data *data);
int		key_press(int keysym, t_data *data);
int		key_release(int keysym, t_data *data);
void		move_forward_back(t_ray *ray, char **map, t_data *data);
void		move_left_right(t_ray *ray, char **map, t_data *data);
void		rotate_right_left(t_data *data, t_ray *ray);
void		rotate_left(t_data *data, t_ray *ray, double olddir_x);
void		img_pix_put(t_img *img, int x, int y, unsigned int color);
int		load_texture(t_data *data);
void		clean_exit(t_data *data, int err);
void		init_texture(t_data *data);
void		draw_texture(t_data *data, int x, int y);
int		destroy_win(t_data *data);

#endif
