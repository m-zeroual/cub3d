/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:56:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/05 10:45:21 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

double	ft_calcul_h(t_cub3d *_cub3d)
{
	int check = 0;
	int check_left = 0;
	if (_cub3d->up_down)
		_cub3d->start.y = (int)(_cub3d->py / PIXEL) * PIXEL;
	else
		_cub3d->start.y = (int)(_cub3d->py / PIXEL) * PIXEL + PIXEL;
	_cub3d->start.x = _cub3d->px + ((_cub3d->py - _cub3d->start.y) / tan(_cub3d->ray_angle * M_PI / 180));
	_cub3d->step.y = PIXEL;
	if(_cub3d->up_down)
		_cub3d->step.y *= -1;
	_cub3d->step.x =  _cub3d->step.y / tan(_cub3d->ray_angle * M_PI / 180);
	if (_cub3d->left_right && _cub3d->step.x < 0)
		_cub3d->step.x *= -1;
	if (!_cub3d->left_right && _cub3d->step.x > 0)
		_cub3d->step.x *= -1;

	if (_cub3d->up_down)
		check = 1;
	if (!_cub3d->left_right)
		check_left = 1;
	_cub3d->horizontal.y = _cub3d->start.y;
	_cub3d->horizontal.x = _cub3d->start.x;
	while (((int)(_cub3d->horizontal.x / PIXEL) - check_left >= 0 && (int)(_cub3d->horizontal.x / PIXEL) - check_left < _cub3d->width)
		&& (((int)_cub3d->horizontal.y / PIXEL) - check >= 0 &&  (int)(_cub3d->horizontal.y / PIXEL) - check < _cub3d->height))
	{
		
		if (_cub3d->map[(int)(((_cub3d->horizontal.y) - check) / PIXEL) + 6][(int)((_cub3d->horizontal.x - check_left) / PIXEL) ] == '1')
			break ;
		_cub3d->horizontal.y += _cub3d->step.y;
		_cub3d->horizontal.x += _cub3d->step.x;
	}
	return (vetagorc(_cub3d->horizontal.x, _cub3d->horizontal.y, _cub3d->px, _cub3d->py));
}

double ft_calcul_v(t_cub3d *_cub3d)
{
	int check = 0;

	if (_cub3d->left_right)
		_cub3d->start.x = (int)(_cub3d->px / PIXEL) * PIXEL + PIXEL;
	else
		_cub3d->start.x = (int)(_cub3d->px / PIXEL) * PIXEL;
	_cub3d->start.y = _cub3d->py + ((_cub3d->px - _cub3d->start.x) * tan(_cub3d->ray_angle * M_PI / 180));

	_cub3d->step.x = PIXEL;
	if(!_cub3d->left_right)
		_cub3d->step.x *= -1;
	_cub3d->step.y =  _cub3d->step.x * tan(_cub3d->ray_angle * M_PI / 180);

	if (_cub3d->up_down && _cub3d->step.y > 0)
		_cub3d->step.y *= -1;

	if (!_cub3d->up_down && _cub3d->step.y < 0)
		_cub3d->step.y *= -1;
	if (!_cub3d->left_right)
		check = 1;

	_cub3d->vertical.y = _cub3d->start.y;
	_cub3d->vertical.x = _cub3d->start.x;
	while (((int)(_cub3d->vertical.x / PIXEL) - check >= 0 && (int)(_cub3d->vertical.x / PIXEL) - check < _cub3d->width)
		&& (((int)_cub3d->vertical.y / PIXEL) >= 0 &&  (int)(_cub3d->vertical.y / PIXEL)  < _cub3d->height))
	{
		if (_cub3d->map[((int)((_cub3d->vertical.y) ) / PIXEL) + 6][(((int)(_cub3d->vertical.x) - check) / PIXEL)] == '1')
			break ;
		_cub3d->vertical.y += _cub3d->step.y;
		_cub3d->vertical.x += _cub3d->step.x;
	}
	return (vetagorc(_cub3d->vertical.x, _cub3d->vertical.y, _cub3d->px, _cub3d->py));
}

// int	create_trgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }

void	draw_sky(t_cub3d *_cub3d, int index, int end)
{
	int	j;

	j = 0;
	while (j < end)
	{
		img_pixl_put(_cub3d, index, j, 0x87CEEB);
		j++;
	}
}

void	draw_floor(t_cub3d *_cub3d, int index, int start)
{
	int	j;

	j = start;
	while (j < HEIGHT)
	{
		img_pixl_put(_cub3d, index, j, 0xD2B48C);
		j++;
	}
}

static void	draw_wall(t_cub3d *_cub3d, double d_ray, int index)
{
	double	projected_wall;
	int		start;
	int		j;

	projected_wall = (double)(HEIGHT / (double)(d_ray * \
	cos((_cub3d->ray_angle - _cub3d->rotation) * M_PI / 180) / PIXEL));
	j = 0;
	start = (int)((HEIGHT / 2) - (projected_wall / 2));
	if (start < 0)
		start = 0;
	draw_sky(_cub3d, index, start);
	while (j < projected_wall && j < HEIGHT)
	{
		img_pixl_put(_cub3d, index, start + j, 0x0000FF);
		j++;
	}
	draw_floor(_cub3d, index, start + j);
}

static void	ft_raycating(t_cub3d *_cub3d, int i)
{
	double	dy;
	double	dx;
	
	ft_check_view(_cub3d);
	dy = ft_calcul_h(_cub3d);
	dx = ft_calcul_v(_cub3d);
	if (dy < dx)
	{
		ft_draw_ray(_cub3d, _cub3d->horizontal.x, _cub3d->horizontal.y, 0x00FF00);
		draw_wall(_cub3d, dy, i);
	}
	else
	{
		ft_draw_ray(_cub3d, _cub3d->vertical.x, _cub3d->vertical.y, 0x00FF00);
		draw_wall(_cub3d, dx, i);
	}
}

void	cast_all_rays(t_cub3d *_cub3d)
{
	int	i;

	i = 0;
	_cub3d->ray_angle = _cub3d->rotation + (VUE_ANGLE / 2);
	while (i < WIDTH)
	{
		_cub3d->ray_angle = normalize_angle(_cub3d->ray_angle);
		ft_raycating(_cub3d, i);
		_cub3d->ray_angle -= VUE_ANGLE / (double)WIDTH;
		i += 1;
	}
}
