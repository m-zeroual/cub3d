/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:53:42 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/14 11:05:30 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

static void	s_w_key(int keyCode, t_cub3d *_cub3d)
{
	float	new_x;
	float	new_y;

	if (keyCode == S_KEY)
	{
		new_x = _cub3d->px - cos(_cub3d->rotation * M_PI / 180) * STEP_MOVE;
		new_y = _cub3d->py - -sin(_cub3d->rotation * M_PI / 180) * STEP_MOVE;
		if (!is_upside_wall_dor(_cub3d, new_x, new_y, '1') \
		&& !is_upside_wall_dor(_cub3d, new_x, new_y, 'D'))
		{
			_cub3d->px = new_x;
			_cub3d->py = new_y;
		}
	}
	else if (keyCode == W_KEY)
	{
		new_x = _cub3d->px + cos(_cub3d->rotation * M_PI / 180) * STEP_MOVE;
		new_y = _cub3d->py + -sin(_cub3d->rotation * M_PI / 180) * STEP_MOVE;
		if (!is_upside_wall_dor(_cub3d, new_x, new_y, '1') \
		&& !is_upside_wall_dor(_cub3d, new_x, new_y, 'D'))
		{
			_cub3d->px = new_x;
			_cub3d->py = new_y;
		}
	}
}

static void	a_d_key(int keyCode, t_cub3d *_cub3d)
{
	float	new_x;
	float	new_y;
	int		new_angle;

	new_angle = 90 - _cub3d->rotation;
	new_angle = normalize_angle(new_angle);
	if (keyCode == A_KEY)
	{
		new_x = _cub3d->px - cos(new_angle * M_PI / 180) * STEP_MOVE;
		new_y = _cub3d->py - sin(new_angle * M_PI / 180) * STEP_MOVE;
		if (!is_upside_wall_dor(_cub3d, new_x, new_y, '1') \
		&& !is_upside_wall_dor(_cub3d, new_x, new_y, 'D'))
			_cub3d->px = ((_cub3d->py = new_y), new_x);
	}
	if (keyCode == D_KEY)
	{
		new_x = _cub3d->px + cos(new_angle * M_PI / 180) * STEP_MOVE;
		new_y = _cub3d->py + sin(new_angle * M_PI / 180) * STEP_MOVE;
		if (!is_upside_wall_dor(_cub3d, new_x, new_y, '1') \
		&& !is_upside_wall_dor(_cub3d, new_x, new_y, 'D'))
			_cub3d->px = ((_cub3d->py = new_y), new_x);
	}
}

static void	open_close_door(t_cub3d *_cub3d)
{
	int	distance;

	distance = sqrt(pow((int)_cub3d->door_hit.x - \
	(int)(_cub3d->px / PIXEL), 2) + \
	pow((int)_cub3d->door_hit.y - (int)(_cub3d->py / PIXEL), 2));
	if (_cub3d->is_door && distance == 1)
	{
		if (_cub3d->map[(int)_cub3d->door_hit.y] \
		[(int)_cub3d->door_hit.x] == 'D')
			_cub3d->map[(int)_cub3d->door_hit.y] \
			[(int)_cub3d->door_hit.x] = 'O';
		else if (_cub3d->map[(int)_cub3d->door_hit.y] \
		[(int)_cub3d->door_hit.x] == 'O')
			_cub3d->map[(int)_cub3d->door_hit.y] \
			[(int)_cub3d->door_hit.x] = 'D';
	}
}

int	mouse_hook(int x, int y, t_cub3d *_cub3d)
{
	(void)y;
	if (_cub3d->mouse_x_pos > x)
		_cub3d->rotation += 2;
	else if (_cub3d->mouse_x_pos < x)
		_cub3d->rotation -= 2;
	_cub3d->mouse_x_pos = x;
	return (0);
}

int	key_hook(int keyCode, t_cub3d *_cub3d)
{
	if (keyCode == ARROW_LEFT)
		_cub3d->rotation += ANGLE_MOVE;
	else if (keyCode == ARROW_RIGHT)
		_cub3d->rotation -= ANGLE_MOVE;
	else if (keyCode == S_KEY || keyCode == W_KEY)
		s_w_key(keyCode, _cub3d);
	else if (keyCode == A_KEY || keyCode == D_KEY)
		a_d_key(keyCode, _cub3d);
	else if (keyCode == D_OPEN)
		open_close_door(_cub3d);
	else if (keyCode == ESC)
		quit(_cub3d);
	ft_draw(_cub3d);
	return (0);
}
