/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:40 by mzeroual          #+#    #+#             */
/*   Updated: 2023/07/26 16:43:38 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	CUB3D_FT
# define CUB3D_FT

# include "./../lib/libft/libft.h"
# include "./../lib/get_next_line/get_next_line.h"
# include "../lib/minilibx_opengl_20191021/mlx.h"
// # include <mlx.h>
# include <math.h>
# include <stdio.h>

# define PIXEL 50
# define PLAYER_SIZE 10

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


typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_scale
{
	int		right_left;
	int		up_down;
}	t_scale;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;


typedef struct s_line
{
	int		delta_x;
	int		delta_y;
	int		incre_x;
	int		incre_y;
	int		error;
	int		e2;
}	t_line;

typedef struct s_cub3d
{
	int     height;
	int     width;
	char    **map;
	void	*mlx_ptr;
	void	*mlx_win;
	float   player_facing;
	int		rotation_angle;
	// float   rotation_angle;
	int     turn_direction;
	int     walk_direction;
	int     step_size;
	int     px;
	int     py;

	t_img   img;
} t_cub3d;

//====> src/check_map/check_error/ft_error.c <=====
void ft_check_error(char *map_name);


//====> src/check_map/check_error/ft_utils.c <=====
void ft_check6lines(char **map);


//====> src/check_map/ft_utils.c <=====
int     ft_count_map(char *map_name);
char    **ft_read_map(char *map_name);
int     ft_count_without_newline(char **map);
char    **ft_clean_map(char **map);
void	ft_free_map(char **map);


//====> src/check_map/parse_map.c <=====
char    **parse_map(char *map_name);


//====> src/cub3d/cub3d.c <=====
void	cub3d(t_cub3d *_cub3d);
void	ft_display(char **map);
void	draw_map(t_cub3d *_cub3d);
void	draw_player(t_cub3d *_cub3d, t_scale scale);
void	draw_line(t_cub3d *_cub3d ,t_point p2);
void	img_pix_put(t_cub3d *_cub3d, int x, int y, int color);



/*#######################################################################
#	 					   EVENTS HANDLER								#
#######################################################################*/

int		key_hook(int key, t_cub3d *_cub3d);
int		ft_close(t_cub3d *_cub3d);

#endif
