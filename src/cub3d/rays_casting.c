/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:56:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/14 16:04:05 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void	check_wall_h(t_cub3d *_cub3d, int *is_door, int check)
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
	return (vetagorc(_cub3d->horizontal.x, _cub3d->horizontal.y\
, _cub3d->px, _cub3d->py));
}

void	check_wall_v(t_cub3d *_cub3d, int *is_door, int check)
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

t_wall	wall_calculations(t_cub3d *_cub3d, t_ray_data ray_data)
{
	double	projected_wall;
	double	err_w;
	t_wall	wall;

	projected_wall = (double)(HEIGHT / (double)(ray_data.ray_lenth * \
	cos((_cub3d->ray_angle - _cub3d->rotation) * M_PI / 180) / PIXEL));
	wall.start = (int)((HEIGHT / 2) - (projected_wall / 2));
	if (wall.start < 0)
		wall.start = 0;
	wall.end = wall.start + projected_wall;
	err_w = (projected_wall / 2) - (HEIGHT / 2);
	if (err_w < 0)
		err_w = 0;
	wall.y_step = ((double)_cub3d->textures[0].height / projected_wall) * err_w;
	if (ray_data.intersection == 1)
		wall.x_step = (_cub3d->textures[0].width / PIXEL) * (ray_data.dest_ray_p.x - (int)(ray_data.dest_ray_p.x / PIXEL) *PIXEL);
	else
		wall.x_step = (_cub3d->textures[0].width / PIXEL) * (ray_data.dest_ray_p.y - (int)(ray_data.dest_ray_p.y / PIXEL) *PIXEL);
	wall.step_size = (double)_cub3d->textures[0].height / projected_wall;
	return (wall);
}

void	draw_3d_game(t_cub3d *_cub3d, t_ray_data ray_data)
{
	t_wall	wall;
	int		j;

	wall = wall_calculations(_cub3d, ray_data);
	j = wall.start;
	while (j < wall.end && j < HEIGHT)
	{
		if (ray_data.wall_or_door == 2)
			img_pixl_put(_cub3d, ray_data.index, j, \
			img_get_pixel_color(_cub3d->textures[4], wall.x_step, wall.y_step));
		else
			img_pixl_put(_cub3d, ray_data.index, j, \
			img_get_pixel_color(_cub3d->textures[get_textur_index(_cub3d, ray_data.intersection)], wall.x_step, wall.y_step));
		wall.y_step += wall.step_size;
		j++;
	}
}

static void	ft_raycating(t_cub3d *_cub3d, t_ray_data ray_data)
{
	ft_check_view(_cub3d);
	ray_data.dy = ft_calcul_h(_cub3d, &ray_data.is_door_h);
	ray_data.dx = ft_calcul_v(_cub3d, &ray_data.is_door_v);
	if (ray_data.dy < ray_data.dx)
	{
		ray_data.dest_ray_p.x = _cub3d->horizontal.x;
		ray_data.dest_ray_p.y = _cub3d->horizontal.y;
		ray_data.wall_or_door = ray_data.is_door_h;
		ray_data.ray_lenth = ray_data.dy;
		ray_data.intersection = 1;
	}
	else
	{
		ray_data.dest_ray_p.x = _cub3d->vertical.x;
		ray_data.dest_ray_p.y = _cub3d->vertical.y;
		ray_data.wall_or_door = ray_data.is_door_v;
		ray_data.ray_lenth = ray_data.dx;
		ray_data.intersection = 2;
	}
	draw_3d_game(_cub3d, ray_data);
	if (_cub3d->is_door == 0)
		is_door(_cub3d, ray_data.dest_ray_p);
}

void	draw_sky_floor(t_cub3d *_cub3d)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				img_pixl_put(_cub3d, x, y, get_color(_cub3d, 1));
			else
				img_pixl_put(_cub3d, x, y, get_color(_cub3d, 2));
			y++;
		}
		x++;
	}
}

void	cast_all_rays(t_cub3d *_cub3d)
{
	t_ray_data	ray_data;
	int			i;

	i = 0;
	_cub3d->ray_angle = _cub3d->rotation + (VUE_ANGLE / 2);
	_cub3d->is_door = 0;
	draw_sky_floor(_cub3d);
	while (i < WIDTH)
	{
		ray_data.wall_or_door = 0;
		ray_data.is_door_v = 0;
		ray_data.is_door_h = 0;
		ray_data.intersection = 0;
		ray_data.index = i;
		_cub3d->ray_angle = normalize_angle(_cub3d->ray_angle);
		ft_raycating(_cub3d, ray_data);
		_cub3d->ray_angle -= VUE_ANGLE / (double)WIDTH;
		i += 1;
	}
}
