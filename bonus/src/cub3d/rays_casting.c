/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:56:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/16 09:45:31 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"

static t_wall	wall_calculations(t_cub3d *_cub3d, t_ray_data ray_data)
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
		wall.x_step = (_cub3d->textures[0].width / PIXEL) * \
		(ray_data.dest_ray_p.x - (int)(ray_data.dest_ray_p.x / PIXEL) *PIXEL);
	else
		wall.x_step = (_cub3d->textures[0].width / PIXEL) * \
		(ray_data.dest_ray_p.y - (int)(ray_data.dest_ray_p.y / PIXEL) *PIXEL);
	wall.step_size = (double)_cub3d->textures[0].height / projected_wall;
	return (wall);
}

static void	draw_3d_game(t_cub3d *_cub3d, t_ray_data ray_data)
{
	t_wall	wall;
	int		j;

	wall = wall_calculations(_cub3d, ray_data);
	j = wall.start;
	while (j < wall.end && j < HEIGHT)
	{
		if (ray_data.wall_or_door == 2)
			img_pixl_put(_cub3d, ray_data.index, j, \
			img_get_pixel_color(_cub3d->textures[4], \
			_cub3d->textures[4].width - wall.x_step, wall.y_step));
		else
			img_pixl_put(_cub3d, ray_data.index, j, \
			img_get_pixel_color(_cub3d->textures[get_textur_index(_cub3d, \
			ray_data.intersection)], _cub3d->textures[get_textur_index(_cub3d, \
			ray_data.intersection)].width - wall.x_step, wall.y_step));
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

static void	draw_sky_floor(t_cub3d *_cub3d)
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
