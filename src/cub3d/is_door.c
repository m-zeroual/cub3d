/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:11:33 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/14 13:12:21 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

static void	_is_door(t_cub3d *_cub3d, t_point point)
{
	if (_cub3d->map[(int)(point.y / PIXEL)][(int)((point.x - 1) / PIXEL)] == 'D' \
	|| _cub3d->map[(int)(point.y / PIXEL)][(int)((point.x - 1) / PIXEL)] == 'O')
	{
		_cub3d->door_hit.x = (point.x - 1) / PIXEL;
		_cub3d->door_hit.y = point.y / PIXEL;
		_cub3d->is_door = 1;
	}
	else if (_cub3d->map[(int)(point.y / PIXEL)][(int)((point.x + 1) / PIXEL)] == 'D' \
	|| _cub3d->map[(int)(point.y / PIXEL)][(int)((point.x + 1) / PIXEL)] == 'O')
	{
		_cub3d->door_hit.x = (point.x + 1) / PIXEL;
		_cub3d->door_hit.y = point.y / PIXEL;
		_cub3d->is_door = 1;
	}
}

void	is_door(t_cub3d *_cub3d, t_point point)
{
	if (_cub3d->map[(int)((point.y + 1) / PIXEL)][(int)(point.x / PIXEL)] == 'D' \
	|| _cub3d->map[(int)((point.y + 1) / PIXEL)][(int)(point.x / PIXEL)] == 'O')
	{
		_cub3d->door_hit.x = point.x / PIXEL;
		_cub3d->door_hit.y = (point.y + 1) / PIXEL;
		_cub3d->is_door = 1;
	}
	else if (_cub3d->map[(int)((point.y - 1) / PIXEL)][(int)(point.x / PIXEL)] == 'D' \
	|| _cub3d->map[(int)((point.y - 1) / PIXEL)][(int)(point.x / PIXEL)] == 'O')
	{
		_cub3d->door_hit.x = point.x / PIXEL;
		_cub3d->door_hit.y = (point.y - 1) / PIXEL;
		_cub3d->is_door = 1;
	}
	else
		_is_door(_cub3d, point);
}