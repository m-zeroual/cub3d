/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:40 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/14 13:12:40 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include "./../lib/libft/libft.h"
# include "./../lib/get_next_line/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define PIXEL 20
# define HEIGHT 1080
# define WIDTH 1920
# define MINI_MAP_HEIGHT 200
# define MINI_MAP_WIDTH 600
# define PLAYER_SIZE 4
# define VUE_ANGLE 60


# define STEP_MOVE 5
# define ANGLE_MOVE 3

#define UP 1
#define DOWN 0
#define RIGHT 1
#define LEFT 0

# define ESC 53


/*---------ALL KEYS---------*/
# define ARROW_RIGHT 124
# define ARROW_LEFT 123
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define D_OPEN 14
# define MINI_MAP 46

# define ON_DESTROY 17
# define ON_MOUSE_MOVE 6
# define ON_KEY_PRESS 2

typedef struct s_draw_ray
{
	float	xincrement;
	float	yincrement;
	float	x;
	float	y;
	int		i;
    int		dx;
	int		dy;
	int		steps;
}	t_draw_ray;


typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_ray_data
{
	int		index;
	t_point	dest_ray_p;
	double	dy;
	double	dx;
	double	ray_lenth;
	int		intersection;
	int		wall_or_door;
	int		is_door_v;
	int		is_door_h;
}	t_ray_data;


typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_wall
{
	double	y_step;
	double	x_step;
	double	step_size;
	int		start;
	int		end;
}	t_wall;

typedef struct s_texture
{
	t_img   img;
	int		height;
	int		width;
	char	*name;
}	t_texture;

typedef struct s_cub3d
{
	int     height;
	int     width;
	char    **map;
	int		index_map;
	int		display_mini_map;
	void	*mlx_ptr;
	void	*mlx_win;
	int		up_down;
	int		left_right;
	float	px;
	float	py;
	int		is_door;
	t_point door_hit;
	t_texture	textures[5];
	char **c_rgb;
	char **f_rgb;
	t_point start;
	t_point step;
	int		mouse_x_pos;
	double	rotation;
	double	ray_angle;
	t_point vertical;
	t_point horizontal;
	t_img   img;
}	t_cub3d;

// -------------- parse map partie ----------------------
//====> src/check_map/check_error/ft_check6lines.c <=====
int	ft_check6lines(char **map, t_cub3d *_cub3d);

//====> src/check_map/check_error/ft_error.c <=====
void ft_check_error(char *map_name);

//====> src/check_map/ft_free_map.c <=====
void	ft_free_map(char **map);
void	ft_free_all(t_cub3d *_cub3d);

//====> src/check_map/ft_utils.c <=====
int		ft_count_without_newline(char **map);
int     ft_count_map(char *map_name);
char    **ft_read_map(char *map_name);
char    **ft_clean_map(char **map, t_cub3d *_cub3d);

//====> src/check_map/parse_map.c <=====
int    parse_map(char *map_name, t_cub3d *_cub3d);
// ------------------------------------------------------


// ---------------- draw map partie -------------------------------------
//====> src/cub3d/cub3d.c <=====
void cub3d(t_cub3d *_cub3d);
void ft_display_map(char **map);

//====> src/cub3d/ft_draw_map.c <=====
void ft_draw_map(t_cub3d *_cub3d);

// -------------------------------------------------------------------------

//====> src/cub3d/control_hooks.c <=====
int	key_hook(int keyCode, t_cub3d *_cub3d);
int	mouse_hook(int x, int y, t_cub3d *_cub3d);

//====> src/cub3d/rays_casting.c <=====
void	cast_all_rays(t_cub3d *_cub3d);

//====> src/cub3d/cub3d_utils.c <=====
void	img_pixl_put(t_cub3d *_cub3d, int x, int y, int color);
void	ft_draw_ray(t_cub3d *_cub3d, int endx, int endy, int color);
double	vetagorc(double x1, double y1, double x, double y);
double	normalize_angle(double angle);
void	ft_check_view(t_cub3d *_cub3d);

//====> src/cub3d/cub3d_utils2.c <=====
void	open_textures(t_cub3d *_cub3d);
int		is_upside_wall_dor(t_cub3d *_cub3d, int x, int y, char wall_dor);
int		img_get_pixel_color(t_texture texture, int x, int y);
int		get_color(t_cub3d *_cub3d, int ceile_or_floor);
int		quit(t_cub3d *_cub3d);

//====> src/cub3d/is_door.c <=====
void	is_door(t_cub3d *_cub3d, t_point point);



int	ft_draw(t_cub3d *_cub3d);

#endif
