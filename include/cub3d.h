/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:40 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/04 23:26:12 by kchaouki         ###   ########.fr       */
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
# define WIDTH 1300
// # define HEIGHT 1080
// # define WIDTH 1920
# define PLAYER_SIZE 6
# define VUE_ANGLE 60

#define UP 1
#define DOWN 0
#define RIGHT 1
#define LEFT 0


# define ESC 53

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2

# define MINUS 78
# define PLUS 69

# define ON_DESTROY 17

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


typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;


typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_cub3d
{
	int     height;
	int     width;
	char    **map;
	void	*mlx_ptr;
	void	*mlx_win;
	int		up_down;
	int		left_right;
	float     px;
	float     py;

	t_point start;
	t_point step;
	

	int     rotation;
	double	ray_angle;

	t_point vertical;
	t_point horizontal;
	t_img   img;
	
} t_cub3d;

// -------------- parse map partie ----------------------
//====> src/check_map/check_error/ft_check6lines.c <=====
int	ft_check6lines(char **map);

//====> src/check_map/check_error/ft_error.c <=====
void ft_check_error(char *map_name);

//====> src/check_map/ft_free_map.c <=====
void	ft_free_map(char **map);

//====> src/check_map/ft_utils.c <=====
int		ft_count_without_newline(char **map);
int     ft_count_map(char *map_name);
char    **ft_read_map(char *map_name);
char    **ft_clean_map(char **map);

//====> src/check_map/parse_map.c <=====
char    **parse_map(char *map_name);
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
int	quit(t_cub3d *_cub3d);


//====> src/cub3d/cub3d_utils.c <=====
void	img_pixl_put(t_cub3d *_cub3d, int x, int y, int color);
void	ft_draw_ray(t_cub3d *_cub3d, int endx, int endy, int color);
double	vetagorc(double x1, double y1, double x, double y);
double	normalize_angle(double angle);
void	ft_check_view(t_cub3d *_cub3d);

//====> src/cub3d/rays_casting.c <=====
void	cast_all_rays(t_cub3d *_cub3d);

#endif
