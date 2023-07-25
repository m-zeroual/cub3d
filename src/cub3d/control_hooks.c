/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:14:30 by kchaouki          #+#    #+#             */
/*   Updated: 2023/07/25 12:09:16 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

static void	redraw_all(t_cub3d *_cub3d, t_scale scale)
{
	mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->img.mlx_img);
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, \
	&_cub3d->img.line_len, &_cub3d->img.endian);
	draw_map(_cub3d);
	draw_player(_cub3d, scale);
	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, 0, 0);
}

static void	close_window(t_cub3d *_cub3d)
{
	mlx_destroy_window(_cub3d->mlx_ptr, _cub3d->mlx_win);
	mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->img.mlx_img);
	// ft_free_all(_cub3d);
	exit(0);
}

int	ft_close(t_cub3d *_cub3d)
{
	close_window(_cub3d);
	return (0);
}

int	key_hook(int key, t_cub3d *_cub3d)
{
	t_scale	scale;

	scale.right_left = 0;
	scale.up_down = 0;
	if (key == ESC)
		close_window(_cub3d);
	else if (key == ARROW_UP)
	{
		scale.up_down = -4;
		printf("UP\n");
	}
	else if (key == ARROW_DOWN)
	{
		scale.up_down = +4;
		printf("DOWN\n");
	}
	else if (key == ARROW_RIGHT)
	{
		scale.right_left = 4;
		printf("RIGHT\n");
	}
	else if (key == ARROW_LEFT)
	{
		scale.right_left = -4;
		printf("LEFT\n");
	}
	redraw_all(_cub3d, scale);
	return (0);
}
