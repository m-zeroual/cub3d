/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:40 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/13 08:44:43 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	CUB3D_FT
# define CUB3D_FT

# include "./../lib/libft/libft.h"
# include "./../lib/get_next_line/get_next_line.h"
# include <mlx.h>
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
    void    *mlx_ptr;
    void    *mlx_win;
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
void cub3d(t_cub3d *_cub3d);
void ft_display(char **map);


#endif
