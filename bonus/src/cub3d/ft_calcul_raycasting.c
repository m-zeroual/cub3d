/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_raycasting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:35:49 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/15 14:39:59 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"

static void	check_wall_h(t_cub3d *_cub3d, int *is_door, int check)
{
	while (((int)(_cub3d->horizontal.x / PIXEL) >= 0
		&& (int)(_cub3d->horizontal.x / PIXEL) < _cub3d->width)
		&& (((int)_cub3d->horizontal.y / PIXEL) - check >= 0
		&& (int)(_cub3d->horizontal.y / PIXEL) - check < _cub3d->height))
	{
		if (_cub3d->map[((int)((_cub3d->horizontal.y) - check) / PIXEL)] \
		[((int)(_cub3d->horizontal.x) / PIXEL)] == '1')
		{
			*is_door = 1;
			break ;
		}
		else if (_cub3d->map[((int)((_cub3d->horizontal.y) - check) / PIXEL)] \
		[((int)(_cub3d->horizontal.x) / PIXEL)] == 'D')
		{
			*is_door = 2;
			break ;
		}
		_cub3d->horizontal.y += _cub3d->step.y;
		_cub3d->horizontal.x += _cub3d->step.x;
	}
}

double	ft_calcul_h(t_cub3d *_cub3d, int *is_door)
{
	int	check;

	check = 0;
	if (_cub3d->up_down)
		_cub3d->start.y = (int)(_cub3d->py / PIXEL) * PIXEL;
	else
		_cub3d->start.y = (int)(_cub3d->py / PIXEL) * PIXEL + PIXEL;
	_cub3d->start.x = _cub3d->px + ((_cub3d->py - _cub3d->start.y) \
	/ tan(_cub3d->ray_angle * M_PI / 180));
	_cub3d->step.y = PIXEL;
	if (_cub3d->up_down)
		_cub3d->step.y *= -1;
	_cub3d->step.x = _cub3d->step.y / tan(_cub3d->ray_angle * M_PI / 180);
	if (_cub3d->left_right && _cub3d->step.x < 0)
		_cub3d->step.x *= -1;
	if (!_cub3d->left_right && _cub3d->step.x > 0)
		_cub3d->step.x *= -1;
	if (_cub3d->up_down)
		check = 1;
	_cub3d->horizontal.y = _cub3d->start.y;
	_cub3d->horizontal.x = _cub3d->start.x;
	check_wall_h(_cub3d, is_door, check);
	return (vetagorc(_cub3d->horizontal.x, _cub3d->horizontal.y \
, _cub3d->px, _cub3d->py));
}

static void	check_wall_v(t_cub3d *_cub3d, int *is_door, int check)
{
	while (((int)(_cub3d->vertical.x / PIXEL) - check >= 0 \
		&& (int)(_cub3d->vertical.x / PIXEL) - check < _cub3d->width) \
		&& (((int)_cub3d->vertical.y / PIXEL) >= 0 \
		&& (int)(_cub3d->vertical.y / PIXEL) < _cub3d->height))
	{
		if (_cub3d->map[((int)((_cub3d->vertical.y)) / PIXEL)] \
		[(((int)(_cub3d->vertical.x) - check) / PIXEL)] == '1')
		{
			*is_door = 1;
			break ;
		}
		else if (_cub3d->map[((int)((_cub3d->vertical.y)) / PIXEL)] \
		[(((int)(_cub3d->vertical.x) - check) / PIXEL)] == 'D')
		{
			*is_door = 2;
			break ;
		}
		_cub3d->vertical.y += _cub3d->step.y;
		_cub3d->vertical.x += _cub3d->step.x;
	}
}

double	ft_calcul_v(t_cub3d *_cub3d, int *is_door)
{
	int	check;

	check = 0;
	if (_cub3d->left_right)
		_cub3d->start.x = (int)(_cub3d->px / PIXEL) * PIXEL + PIXEL;
	else
		_cub3d->start.x = (int)(_cub3d->px / PIXEL) * PIXEL;
	_cub3d->start.y = _cub3d->py + ((_cub3d->px - _cub3d->start.x) \
	* tan(_cub3d->ray_angle * M_PI / 180));
	_cub3d->step.x = PIXEL;
	if (!_cub3d->left_right)
		_cub3d->step.x *= -1;
	_cub3d->step.y = _cub3d->step.x * tan(_cub3d->ray_angle * M_PI / 180);
	if (_cub3d->up_down && _cub3d->step.y > 0)
		_cub3d->step.y *= -1;
	if (!_cub3d->up_down && _cub3d->step.y < 0)
		_cub3d->step.y *= -1;
	if (!_cub3d->left_right)
		check = 1;
	_cub3d->vertical.y = _cub3d->start.y;
	_cub3d->vertical.x = _cub3d->start.x;
	check_wall_v(_cub3d, is_door, check);
	return (vetagorc(_cub3d->vertical.x, _cub3d->vertical.y \
	, _cub3d->px, _cub3d->py));
}

int	get_textur_index(t_cub3d *_cub3d, int intersection)
{
	if (intersection == 1 && _cub3d->up_down)
		return (0);
	else if (intersection == 1 && !_cub3d->up_down)
		return (1);
	else if (intersection == 2 && _cub3d->left_right)
		return (2);
	else if (intersection == 2 && !_cub3d->left_right)
		return (3);
	return (0);
}
