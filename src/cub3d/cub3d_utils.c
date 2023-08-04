/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:53:41 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/04 23:25:45 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void	img_pixl_put(t_cub3d *_cub3d, int x, int y, int color)
{
	char    *pixel;

    pixel = _cub3d->img.addr + (y * _cub3d->img.line_len + x * (_cub3d->img.bpp / 8));
	*(int *)pixel = color;
}

void	ft_draw_ray(t_cub3d *_cub3d, int endx, int endy, int color)
{
	t_draw_ray	ray;

	ray.dx = endx - _cub3d->px;
	ray.dy = endy - _cub3d->py;
	if (abs(ray.dx) > abs(ray.dy))
		ray.steps = abs(ray.dx);
	else
		ray.steps = abs(ray.dy);
	ray.xincrement = (float)ray.dx / ray.steps;
	ray.yincrement = (float)ray.dy / ray.steps;
	ray.x = _cub3d->px;
	ray.y = _cub3d->py;
	ray.i = 0;
	while (ray.i <= ray.steps)
	{
		if (ray.x >= 0 && ray.x < _cub3d->width * PIXEL \
		&& ray.y >= 0 && ray.y < _cub3d->height * PIXEL)
			img_pixl_put(_cub3d, (int)ray.x, (int)ray.y, color);
		ray.x += ray.xincrement;
		ray.y += ray.yincrement;
		ray.i++;
	}
}

void	ft_check_view(t_cub3d *_cub3d)
{
	if (_cub3d->ray_angle > 0 && _cub3d->ray_angle <= 180)
		_cub3d->up_down = UP;
	else
		_cub3d->up_down = DOWN;
	if (_cub3d->ray_angle >= 90 && _cub3d->ray_angle < 270)
		_cub3d->left_right = LEFT;
	else
		_cub3d->left_right = RIGHT;
}

double	normalize_angle(double angle)
{
	if (angle > 0)
		angle = fmod(angle, 360);
	if (angle < 0)
		angle = fmod((360 + angle), 360);
	return (angle);
}

double	vetagorc(double x1, double y1, double x, double y)
{
	return (sqrt(pow((x1 - x), 2) + pow((y1 - y), 2)));
}
