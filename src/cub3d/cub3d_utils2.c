/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:58:47 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/07 12:27:50 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

int	quit(t_cub3d *_cub3d)
{
	mlx_destroy_window(_cub3d->mlx_ptr, _cub3d->mlx_win);
	// mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->img.mlx_img);
	// ft_free_all(_cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}

int	img_get_pixel_color(t_cub3d *_cub3d, int x, int y)
{
	char	*pixel;

	pixel = _cub3d->east.img.addr + (y * _cub3d->east.img.line_len + \
	x * (_cub3d->east.img.bpp / 8));
	return (*(int *)pixel);
}

// void	ft_free_all(t_cub3d *_cub3d)
// {
	
// }
