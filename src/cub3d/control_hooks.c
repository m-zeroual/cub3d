/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:14:30 by kchaouki          #+#    #+#             */
/*   Updated: 2023/07/26 16:46:52 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

static void	redraw_all(t_cub3d *_cub3d, t_scale scale)
{
	mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->img.mlx_img);
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, 
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
	else if (key == W_KEY)
		scale.up_down = -_cub3d->step_size;
	else if (key == S_KEY)
		scale.up_down = _cub3d->step_size;
	else if (key == D_KEY)
		scale.right_left = _cub3d->step_size;
	else if (key == A_KEY)
		scale.right_left = -_cub3d->step_size;
	else if (key == ARROW_RIGHT)
	{
		printf("CAMERA RIGHT\n");
		_cub3d->rotation_angle -= 2;
	}
	else if (key == ARROW_LEFT)
	{
		printf("CAMERA LEFT\n");
		_cub3d->rotation_angle += 2;
		
	}
	else if (key == MINUS)
	{
		if (_cub3d->step_size > 0)
			_cub3d->step_size -= 1;
	}
	else if (key == PLUS)
	{
		if (_cub3d->step_size < 50)
			_cub3d->step_size += 1;
	}
	redraw_all(_cub3d, scale);
	return (0);
}
