/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:40 by mzeroual          #+#    #+#             */
/*   Updated: 2023/07/28 22:18:15 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	CUB3D_FT
# define CUB3D_FT

# include "./../lib/libft/libft.h"
# include "./../lib/get_next_line/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

#define PIXEL 50

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_cub3d
{
	int     height;
	int     width;
	char    **map;
	void	*mlx_ptr;
	void	*mlx_win;
	int     px;
	int     py;

	int     	endx;
	int     	endy;
	int     rotation;





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

//====> src/cub3d/img_pix_put.c <=====
void	img_pixl_put(t_cub3d *_cub3d, int x, int y, int color);
// -------------------------------------------------------------------------


#endif
