/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:56:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/10 10:21:22 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

double	ft_calcul_h(t_cub3d *_cub3d)
{
	int check = 0;

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

	_cub3d->horizontal.y = _cub3d->start.y;
	_cub3d->horizontal.x = _cub3d->start.x;
	while (((int)(_cub3d->horizontal.x / PIXEL) >= 0 && (int)(_cub3d->horizontal.x / PIXEL) < _cub3d->width)
		&& (((int)_cub3d->horizontal.y / PIXEL) - check >= 0 &&  (int)(_cub3d->horizontal.y / PIXEL) - check < _cub3d->height))
	{
		
		if (_cub3d->map[(int)(((_cub3d->horizontal.y) - check) / PIXEL) + 6][(int)((_cub3d->horizontal.x ) / PIXEL) ] == '1')
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

void	draw_sky(t_cub3d *_cub3d, int index, int end)
{
	int	j;

	j = 0;
	while (j < end)
	{
		// img_pixl_put(_cub3d, index, j, 0x87CEEB);
		img_pixl_put(_cub3d, index, j, get_color(_cub3d, 1));
		j++;
	}
}

void	draw_floor(t_cub3d *_cub3d, int index, int start)
{
	int	j;

	j = start;
	while (j < HEIGHT)
	{
		img_pixl_put(_cub3d, index, j, get_color(_cub3d, 0));
		// img_pixl_put(_cub3d, index, j, 0xD2B48C);
		j++;
	}
}

static void	draw_wall(t_cub3d *_cub3d, t_point dest_ray_p, double d_ray, int index, int intersection)
{
	double	projected_wall;
	int		start;
	int		x_step;
	(void) dest_ray_p;
	double	y_step;
	int		j;
	// int		color;

	projected_wall = (double)(HEIGHT / (double)(d_ray * \
	cos((_cub3d->ray_angle - _cub3d->rotation) * M_PI / 180) / PIXEL));
	j = 0;
	start = (int)((HEIGHT / 2) - (projected_wall / 2));
	if (start < 0)
		start = 0;
	draw_sky(_cub3d, index, start);
	y_step = 0;
	// if (_cub3d->ray_angle > 60 && _cub3d->ray_angle < 120)
	if (_cub3d->ray_angle > 45 && _cub3d->ray_angle < 135)
	{
		if (intersection == 1)
			x_step = (_cub3d->textures[0].width / PIXEL) * (dest_ray_p.x - (int)(dest_ray_p.x / PIXEL) * PIXEL);
		// x_step = (_cub3d->east.width / PIXEL) * fmod((dest_ray_p.x / PIXEL), PIXEL);
		else
			x_step = (_cub3d->textures[0].width / PIXEL) * (dest_ray_p.y - (int)(dest_ray_p.y / PIXEL) * PIXEL);
		// printf("VALUE: %lf\n", step);
		while (j < projected_wall && j < HEIGHT)
		{
			// img_pixl_put(_cub3d, index, start + j, img_get_pixel_color(_cub3d, x_step, y_step, 0));

			img_pixl_put(_cub3d, index, start + j, 0x0000FF);
			y_step += (double)_cub3d->textures[0].height / projected_wall;
			j++;
		}
		// printf("up %s\n", _cub3d->textures[0].name);

	}
	// else 	if (_cub3d->ray_angle > 225 && _cub3d->ray_angle < 315)
	// {
	// 	if (intersection == 1)
	// 		x_step = (_cub3d->textures[1].width / PIXEL) * (dest_ray_p.x - (int)(dest_ray_p.x / PIXEL) * PIXEL);
	// 	// x_step = (_cub3d->east.width / PIXEL) * fmod((dest_ray_p.x / PIXEL), PIXEL);
	// 	else
	// 		x_step = (_cub3d->textures[1].width / PIXEL) * (dest_ray_p.y - (int)(dest_ray_p.y / PIXEL) * PIXEL);
	// 	// printf("VALUE: %lf\n", step);
	// 	while (j < projected_wall && j < HEIGHT)
	// 	{
	// 		img_pixl_put(_cub3d, index, start + j, img_get_pixel_color(_cub3d, x_step, y_step, 1));

	// 		// img_pixl_put(_cub3d, index, start + j, 0x0000FF);
	// 		y_step += (double)_cub3d->textures[1].height / projected_wall;
	// 		j++;
	// 	}
	// 	// printf("down %s\n", _cub3d->textures[1].name);
	// }
	// else 	if (_cub3d->ray_angle > 135 && _cub3d->ray_angle < 225)
	// {
	// 	if (intersection == 1)
	// 		x_step = (_cub3d->textures[2].width / PIXEL) * (dest_ray_p.x - (int)(dest_ray_p.x / PIXEL) * PIXEL);
	// 	// x_step = (_cub3d->east.width / PIXEL) * fmod((dest_ray_p.x / PIXEL), PIXEL);
	// 	else
	// 		x_step = (_cub3d->textures[2].width / PIXEL) * (dest_ray_p.y - (int)(dest_ray_p.y / PIXEL) * PIXEL);
	// 	// printf("VALUE: %lf\n", step);
	// 	while (j < projected_wall && j < HEIGHT)
	// 	{
	// 		img_pixl_put(_cub3d, index, start + j, img_get_pixel_color(_cub3d, x_step, y_step, 2));

	// 		// img_pixl_put(_cub3d, index, start + j, 0x0000FF);
	// 		y_step += (double)_cub3d->textures[2].height / projected_wall;
	// 		j++;
	// 	}
	// 	// printf("right %s\n", _cub3d->textures[2].name);

	// }
	// else
	// {
	// 	if (intersection == 1)
	// 		x_step = (_cub3d->textures[3].width / PIXEL) * (dest_ray_p.x - (int)(dest_ray_p.x / PIXEL) * PIXEL);
	// 	// x_step = (_cub3d->east.width / PIXEL) * fmod((dest_ray_p.x / PIXEL), PIXEL);
	// 	else
	// 		x_step = (_cub3d->textures[3].width / PIXEL) * (dest_ray_p.y - (int)(dest_ray_p.y / PIXEL) * PIXEL);
	// 	// printf("VALUE: %lf\n", step);
	// 	while (j < projected_wall && j < HEIGHT)
	// 	{
	// 		img_pixl_put(_cub3d, index, start + j, img_get_pixel_color(_cub3d, x_step, y_step, 3));

	// 		// img_pixl_put(_cub3d, index, start + j, 0x0000FF);
	// 		y_step += (double)_cub3d->textures[3].height / projected_wall;
	// 		j++;
	// 	}
	// 	// printf("left %s\n", _cub3d->textures[3].name);
	// }
	draw_floor(_cub3d, index, start + j);
	// usleep(30);
	if (index == WIDTH - 1)
	printf("ray      =>  %f\n", _cub3d->ray_angle);
		
	// printf("rotation =>  %f\n", _cub3d->rotation);
}

static void	ft_raycating(t_cub3d *_cub3d, int i)
{
	double	dy;
	double	dx;
	t_point	point;
	
	ft_check_view(_cub3d);
	dy = ft_calcul_h(_cub3d);
	dx = ft_calcul_v(_cub3d);
	if (dy < dx)
	{
		ft_draw_ray(_cub3d, _cub3d->horizontal.x, _cub3d->horizontal.y, 0x00FF00);
		point.x = _cub3d->horizontal.x;
		point.y = _cub3d->horizontal.y;
		draw_wall(_cub3d, point, dy, i, 1);
	}
	else
	{
		ft_draw_ray(_cub3d, _cub3d->vertical.x, _cub3d->vertical.y, 0x00FF00);
		point.x = _cub3d->vertical.x;
		point.y = _cub3d->vertical.y;
		draw_wall(_cub3d, point, dx, i, 2);
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
