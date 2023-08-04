/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:53:42 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/04 23:18:28 by kchaouki         ###   ########.fr       */
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

int	is_upside_wall(t_cub3d *_cub3d, int x, int y)
{
	if (_cub3d->map[(int)((y + PLAYER_SIZE / 2) / PIXEL) + 6] \
	[(int)(x / PIXEL)] == '1')
		return (1);
	else if (_cub3d->map[(int)((y - PLAYER_SIZE / 2) / PIXEL) + 6] \
	[(int)(x / PIXEL)] == '1')
		return (1);
	else if (_cub3d->map[(int)(y / PIXEL) + 6] \
	[(int)((x - PLAYER_SIZE / 2) / PIXEL)] == '1')
		return (1);
	else if (_cub3d->map[(int)(y / PIXEL) + 6] \
	[(int)((x + PLAYER_SIZE / 2) / PIXEL)] == '1')
		return (1);
	return (0);
}

void	s_w_key(int keyCode, t_cub3d *_cub3d)
{
	float	new_x;
	float	new_y;

	if (keyCode == S_KEY)
	{
		new_x = _cub3d->px - cos(_cub3d->rotation * M_PI / 180) * 2;
		new_y = _cub3d->py - -sin(_cub3d->rotation * M_PI / 180) * 2;
		if (!is_upside_wall(_cub3d, new_x, new_y))
		{
			_cub3d->px = new_x;
			_cub3d->py = new_y;
		}
	}
	else if (keyCode == W_KEY)
	{
		new_x = _cub3d->px + cos(_cub3d->rotation * M_PI / 180) * 2;
		new_y = _cub3d->py + -sin(_cub3d->rotation * M_PI / 180) * 2;
		if (!is_upside_wall(_cub3d, new_x, new_y))
		{
			_cub3d->px = new_x;
			_cub3d->py = new_y;
		}
	}
}

void	a_d_key(int keyCode, t_cub3d *_cub3d)
{
	float	new_x;
	float	new_y;
	int		new_angle;

	new_angle = 90 - _cub3d->rotation;
	new_angle = normalize_angle(new_angle);
	if (keyCode == A_KEY)
	{
		new_x = _cub3d->px - cos(new_angle * M_PI / 180) * 2;
		new_y = _cub3d->py - sin(new_angle * M_PI / 180) * 2;
		if (!is_upside_wall(_cub3d, new_x, new_y))
			_cub3d->px = ((_cub3d->py = new_y), new_x);
	}
	if (keyCode == D_KEY)
	{
		new_x = _cub3d->px + cos(new_angle * M_PI / 180) * 2;
		new_y = _cub3d->py + sin(new_angle * M_PI / 180) * 2;
		if (!is_upside_wall(_cub3d, new_x, new_y))
			_cub3d->px = ((_cub3d->py = new_y), new_x);
	}
}

int	key_hook(int keyCode, t_cub3d *_cub3d)
{
	if (keyCode == ARROW_LEFT)
		_cub3d->rotation += 1;
	else if (keyCode == ARROW_RIGHT)
		_cub3d->rotation -= 1;
	else if (keyCode == S_KEY || keyCode == W_KEY)
		s_w_key(keyCode, _cub3d);
	else if (keyCode == A_KEY || keyCode == D_KEY)
		a_d_key(keyCode, _cub3d);
	else if (keyCode == ESC)
		quit(_cub3d);
	return (0);
}
