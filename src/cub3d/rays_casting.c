/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:56:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/10 17:06:54 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

double	ft_calcul_h(t_cub3d *_cub3d, int *is_door)
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
		
		// if (_cub3d->map[(int)(((_cub3d->horizontal.y) - check) / PIXEL) + 6][(int)((_cub3d->horizontal.x ) / PIXEL) ] == '1')
		// printf("value is: [%c]\n", _cub3d->map[((int)((_cub3d->horizontal.y) - check) / PIXEL) + 6][((int)(_cub3d->horizontal.x ) / PIXEL)]);
		if (_cub3d->map[((int)((_cub3d->horizontal.y) - check) / PIXEL) + 6][((int)(_cub3d->horizontal.x ) / PIXEL)] == '1')
		{
			*is_door = 1;
			break ;
		}
		else if (_cub3d->map[((int)((_cub3d->horizontal.y) - check) / PIXEL) + 6][((int)(_cub3d->horizontal.x ) / PIXEL)] == 'D')
		{
			*is_door = 2;
			break ;
		}
		_cub3d->horizontal.y += _cub3d->step.y;
		_cub3d->horizontal.x += _cub3d->step.x;
	}
	return (vetagorc(_cub3d->horizontal.x, _cub3d->horizontal.y, _cub3d->px, _cub3d->py));
}

double ft_calcul_v(t_cub3d *_cub3d, int *is_door)
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
		{
			*is_door = 1;
			break ;
		}
		else if (_cub3d->map[((int)((_cub3d->vertical.y) ) / PIXEL) + 6][(((int)(_cub3d->vertical.x) - check) / PIXEL)] == 'D')
		{
			*is_door = 2;
			break ;
		}
		_cub3d->vertical.y += _cub3d->step.y;
		_cub3d->vertical.x += _cub3d->step.x;
	}
	return (vetagorc(_cub3d->vertical.x, _cub3d->vertical.y, _cub3d->px, _cub3d->py));
}

// void	draw_sky(t_cub3d *_cub3d, int index, int end)
// {
// 	int	j;

// 	j = 0;
// 	while (j < end)
// 	{
// 		// img_pixl_put(_cub3d, index, j, 0x87CEEB);
// 		img_pixl_put(_cub3d, index, j, get_color(_cub3d, 1));
// 		j++;
// 	}
// }

// void	draw_floor(t_cub3d *_cub3d, int index, int start)
// {
// 	int	j;

// 	j = start;
// 	while (j < HEIGHT)
// 	{
// 		img_pixl_put(_cub3d, index, j, get_color(_cub3d, 0));
// 		// img_pixl_put(_cub3d, index, j, 0xD2B48C);
// 		j++;
// 	}
// }

// static void	draw_3d_game(t_cub3d *_cub3d, t_point dest_ray_p, double d_ray, int index, int intersection)
static void	draw_3d_game(t_cub3d *_cub3d, t_ray_data ray_data)
{
	double	projected_wall;
	double	y_step;
	double	x_step;
	int		start;
	int		j;

	projected_wall = (double)(HEIGHT / (double)(ray_data.ray_lenth * \
	cos((_cub3d->ray_angle - _cub3d->rotation) * M_PI / 180) / PIXEL));
	j = 0;
	start = (int)((HEIGHT / 2) - (projected_wall / 2));
	if (start < 0)
		start = 0;
	y_step = 0;
	if (ray_data.intersection == 1)
		x_step = (_cub3d->textures[0].width / PIXEL) * (ray_data.dest_ray_p.x - (int)(ray_data.dest_ray_p.x / PIXEL) * PIXEL);
	else
		x_step = (_cub3d->textures[0].width / PIXEL) * (ray_data.dest_ray_p.y - (int)(ray_data.dest_ray_p.y / PIXEL) * PIXEL);
	double err_w = (projected_wall / 2) - (HEIGHT / 2);
	if (err_w < 0)
		err_w = 0;
	y_step = ((double)_cub3d->textures[0].height / projected_wall) * err_w;
	while (j < HEIGHT)
	{
		if (j < start)
			img_pixl_put(_cub3d, ray_data.index, j, get_color(_cub3d, 1));
		else if (j >= start && j < start + projected_wall)
		{
			if (ray_data.wall_or_door == 2)
				img_pixl_put(_cub3d, ray_data.index, j, img_get_pixel_color(_cub3d->textures[4], x_step, y_step));
			else 
			{
				if (ray_data.intersection == 1 && _cub3d->up_down)
					img_pixl_put(_cub3d, ray_data.index, j, img_get_pixel_color(_cub3d->textures[0], x_step, y_step));
				if (ray_data.intersection == 1 && !_cub3d->up_down)
					img_pixl_put(_cub3d, ray_data.index, j, img_get_pixel_color(_cub3d->textures[1], x_step, y_step));
				if (ray_data.intersection == 2 && _cub3d->left_right)
					img_pixl_put(_cub3d, ray_data.index, j, img_get_pixel_color(_cub3d->textures[2], x_step, y_step));
				if (ray_data.intersection == 2 && !_cub3d->left_right)
					img_pixl_put(_cub3d, ray_data.index, j, img_get_pixel_color(_cub3d->textures[3], x_step, y_step));
			}
			y_step += (double)_cub3d->textures[0].height / projected_wall;
			// img_pixl_put(_cub3d, index, j, 0x0000FF);
		}
		else if (j > start + projected_wall)
			img_pixl_put(_cub3d, ray_data.index, j, get_color(_cub3d, 2));
		j++;
	}
	// double err_w = (projected_wall / 2) - (HEIGHT / 2);
	// if(err_w < 0)
	// 	err_w = 0;
	// y_step = ((double)_cub3d->textures[0].height / projected_wall) * err_w;
	// draw_sky(_cub3d, index, start);
	// while (j < projected_wall && j < HEIGHT)
	// {
		// if (_cub3d->wall_door == 2)
		// 	img_pixl_put(_cub3d, index, start + j, img_get_pixel_color(_cub3d->textures[4], x_step, y_step));
		// else 
		// {
		// 	if (intersection == 1 && _cub3d->up_down)
		// 		img_pixl_put(_cub3d, index, start + j, img_get_pixel_color(_cub3d->textures[0], x_step, y_step));
		// 	if (intersection == 1 && !_cub3d->up_down)
		// 		img_pixl_put(_cub3d, index, start + j, img_get_pixel_color(_cub3d->textures[1], x_step, y_step));
		// 	if (intersection == 2 && _cub3d->left_right)
		// 		img_pixl_put(_cub3d, index, start + j, img_get_pixel_color(_cub3d->textures[2], x_step, y_step));
		// 	if (intersection == 2 && !_cub3d->left_right)
		// 		img_pixl_put(_cub3d, index, start + j, img_get_pixel_color(_cub3d->textures[3], x_step, y_step));
		// }
	// 	y_step += (double)_cub3d->textures[0].height / projected_wall;
	// 	j++;
	// }
	// draw_floor(_cub3d, index, start + j);
}

void	_is_door(t_cub3d *_cub3d, t_point point)
{
	if (_cub3d->map[(int)(point.y / PIXEL) + 6][(int)((point.x - 1) / PIXEL)] == 'D' \
	|| _cub3d->map[(int)(point.y / PIXEL) + 6][(int)((point.x - 1) / PIXEL)] == 'O')
	{
		_cub3d->door_hit.x = (point.x - 1) / PIXEL;
		_cub3d->door_hit.y = point.y / PIXEL;
		_cub3d->is_door = 1;
	}
	else if (_cub3d->map[(int)(point.y / PIXEL) + 6][(int)((point.x + 1) / PIXEL)] == 'D' \
	|| _cub3d->map[(int)(point.y / PIXEL) + 6][(int)((point.x + 1) / PIXEL)] == 'O')
	{
		_cub3d->door_hit.x = (point.x + 1) / PIXEL;
		_cub3d->door_hit.y = point.y / PIXEL;
		_cub3d->is_door = 1;
	}
}
void	is_door(t_cub3d *_cub3d, t_point point)
{
	if (_cub3d->map[(int)((point.y + 1) / PIXEL) + 6][(int)(point.x / PIXEL)] == 'D' \
	|| _cub3d->map[(int)((point.y + 1) / PIXEL) + 6][(int)(point.x / PIXEL)] == 'O')
	{
		_cub3d->door_hit.x = point.x / PIXEL;
		_cub3d->door_hit.y = (point.y + 1) / PIXEL;
		_cub3d->is_door = 1;
	}
	else if (_cub3d->map[(int)((point.y - 1) / PIXEL) + 6][(int)(point.x / PIXEL)] == 'D' \
	|| _cub3d->map[(int)((point.y - 1) / PIXEL) + 6][(int)(point.x / PIXEL)] == 'O')
	{
		_cub3d->door_hit.x = point.x / PIXEL;
		_cub3d->door_hit.y = (point.y - 1) / PIXEL;
		_cub3d->is_door = 1;
	}
	else
		_is_door(_cub3d, point);
}

static void	ft_raycating(t_cub3d *_cub3d, t_ray_data ray_data)
{
	ft_check_view(_cub3d);
	ray_data.dy = ft_calcul_h(_cub3d, &ray_data.is_door_h);
	ray_data.dx = ft_calcul_v(_cub3d, &ray_data.is_door_v);
	if (ray_data.dy < ray_data.dx)
	{
		ft_draw_ray(_cub3d, _cub3d->horizontal.x, _cub3d->horizontal.y, 0x00FF00);
		ray_data.dest_ray_p.x = _cub3d->horizontal.x;
		ray_data.dest_ray_p.y = _cub3d->horizontal.y;
		ray_data.wall_or_door = ray_data.is_door_h;
		ray_data.ray_lenth = ray_data.dy;
		ray_data.intersection = 1;
	}
	else
	{
		ft_draw_ray(_cub3d, _cub3d->vertical.x, _cub3d->vertical.y, 0x00FF00);
		ray_data.dest_ray_p.x = _cub3d->vertical.x;
		ray_data.dest_ray_p.y = _cub3d->vertical.y;
		ray_data.wall_or_door = ray_data.is_door_v;
		ray_data.ray_lenth = ray_data.dx;
		ray_data.intersection = 2;
	}
	draw_3d_game(_cub3d, ray_data);
	if (_cub3d->ray_angle > (_cub3d->rotation - 10) && _cub3d->ray_angle < (_cub3d->rotation + 10) && _cub3d->is_door == 0)
		is_door(_cub3d, ray_data.dest_ray_p);
}

// static void	ft_raycating(t_cub3d *_cub3d, int ray_index)
// {
// 	t_point	point;
// 	double	dy;
// 	double	dx;
// 	int		is_door_v;
// 	int		is_door_h;

// 	is_door_v = 0;
// 	is_door_h = 0;
// 	ft_check_view(_cub3d);
// 	dy = ft_calcul_h(_cub3d, &is_door_h);
// 	dx = ft_calcul_v(_cub3d, &is_door_v);
// 	if (dy < dx)
// 	{
// 		ft_draw_ray(_cub3d, _cub3d->horizontal.x, _cub3d->horizontal.y, 0x00FF00);
// 		point.x = _cub3d->horizontal.x;
// 		point.y = _cub3d->horizontal.y;
// 		_cub3d->wall_door = is_door_h;
// 		draw_3d_game(_cub3d, point, dy, ray_index, 1);
// 	}
// 	else
// 	{
// 		ft_draw_ray(_cub3d, _cub3d->vertical.x, _cub3d->vertical.y, 0x00FF00);
// 		point.x = _cub3d->vertical.x;
// 		point.y = _cub3d->vertical.y;
// 		_cub3d->wall_door = is_door_v;
// 		draw_3d_game(_cub3d, point, dx, ray_index, 2);
// 		// draw_3d_game(_cub3d, point, dx, ray_index, 2);
// 	}
// 	if (_cub3d->ray_angle > (_cub3d->rotation - 10) && _cub3d->ray_angle < (_cub3d->rotation + 10) && _cub3d->is_door == 0)
// 		is_door(_cub3d, point);
// }

void	cast_all_rays(t_cub3d *_cub3d)
{
	t_ray_data	ray_data;
	int	i;

	i = 0;
	_cub3d->ray_angle = _cub3d->rotation + (VUE_ANGLE / 2);
	_cub3d->is_door = 0;
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
