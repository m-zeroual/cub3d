/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:58:47 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/07 21:51:17 by mzeroual         ###   ########.fr       */
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

int	img_get_pixel_color(t_cub3d *_cub3d, int x, int y, int pos)
{
	char	*pixel;

	pixel = _cub3d->textures[pos].img.addr + (y * _cub3d->textures[pos].img.line_len + \
	x * (_cub3d->textures[pos].img.bpp / 8));
	return (*(int *)pixel);
}

int	get_color(t_cub3d *_cub3d, int ceile_or_floor)
{
	int	r;
	int	g;
	int	b;

	if (ceile_or_floor == 1)
	{
		r = ft_atoi(_cub3d->c_rgb[0]);
		g = ft_atoi(_cub3d->c_rgb[1]);
		b = ft_atoi(_cub3d->c_rgb[2]);
	}
	else
	{
		r = ft_atoi(_cub3d->f_rgb[0]);
		g = ft_atoi(_cub3d->f_rgb[1]);
		b = ft_atoi(_cub3d->f_rgb[2]);
	}
	return (r << 16 | g << 8 | b);
}

// void	ft_free_all(t_cub3d *_cub3d)
// {
	
// }
