/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:53:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/07/31 19:18:05 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void ft_count(t_cub3d *_cub3d, int *width, int *height)
{
	int i;
	int j;

	i = 6;
	*width = 0;
	*height = 0;
	while (_cub3d->map[i])
	{
		j = 0;
		while (_cub3d->map[i][j])
		{
			if ((_cub3d->map[i][j] == 'W' || _cub3d->map[i][j] == 'N'
				|| _cub3d->map[i][j] == 'E' || _cub3d->map[i][j] == 'S'))
			{
				_cub3d->px = (j * PIXEL) + (PIXEL / 2);
				_cub3d->py = ((i - 6) * PIXEL) + (PIXEL / 2);
			}
			j++;
		}
		if (*width < j)
			*width = j;
		(*height)++;
		i++;
	}
}

void ft_put_pixle(t_cub3d *_cub3d, char c, int x1, int y1)
{
	int y;
	int x;

	y = 0;
	y1 = y1 - 6;
	while (y < PIXEL)
	{
		x = 0;
		while (x < PIXEL)
		{
			if (c == '1')
				img_pix_put(_cub3d, (x1 * PIXEL) + (x ), (y1 * PIXEL) + (y), 0x808080);
			img_pix_put(_cub3d, (x1 * PIXEL) + x, y1 * PIXEL, 0x0000FF);
			if (y1 == _cub3d->height - 1)
				img_pix_put(_cub3d, (x1 * PIXEL) + x, y1 * PIXEL + PIXEL, 0x0000FF);
			x++;
		}
		img_pix_put(_cub3d, (x1 * PIXEL), (y1 * PIXEL) + y, 0x0000FF);
		if (x1 == _cub3d->width - 1)
			img_pix_put(_cub3d, (x1 * PIXEL) + PIXEL, (y1 * PIXEL) + y, 0x0000FF);
		y++;
	}
}

void draw_map(t_cub3d *_cub3d)
{
	int y;
	int x;

	y = 6;
	while (y < _cub3d->height + 6)
	{
		x = 0;
		while (x < _cub3d->width)
		{
			if (_cub3d->map[y][x] == '1' && x <= (int)ft_strlen(_cub3d->map[y]))
				ft_put_pixle(_cub3d, '1', x, y);
			ft_put_pixle(_cub3d, '0', x, y);
			x++;
		}
		y++;
	}
}

int	horisontal_intersection(t_cub3d *_cub3d, t_point *dest)
{
	int	start_y;
	int	start_x;

	start_y = (int)(_cub3d->py / PIXEL)  * PIXEL;
	start_x = start_y + ((_cub3d->py - start_y) / tan(_cub3d->rotation_angle));
	while (1)
	{
		if (_cub3d->map[start_y / PIXEL + 6][start_y / PIXEL] == '1')
			break;
		if (_cub3d->rotation_angle >= 0 && _cub3d->rotation_angle <= 180)
			start_y += PIXEL;
		else
			start_y -= PIXEL;
		start_x += start_y / tan(_cub3d->rotation_angle);
	}
	dest->x = start_x;
	dest->y = start_y;
	return (sqrt(pow(start_x, 2) + pow(start_y, 2)));
}

// void	point_rotation(t_cub3d *_cub3d, float *x, float *y, int rotation_angle)
// {
// 	if (_cub3d->rotation_angle > 0)
// 			_cub3d->rotation_angle = _cub3d->rotation_angle % 360;
// 	if (_cub3d->rotation_angle <= 0)
// 		_cub3d->rotation_angle = (360 + _cub3d->rotation_angle) % 360;
// 	x += cos(_cub3d->rotation_angle * M_PI / 180) * line_lenth;
// 	y += sin(_cub3d->rotation_angle * M_PI / 180) * line_lenth;
// }

void	draw_ray(t_cub3d *_cub3d)
{
	t_point	dest;
	int		line_lenth;

	dest.x = _cub3d->px;
	dest.y = _cub3d->py;
	// horisontal_intersection(_cub3d, dest);
	line_lenth = 50;
	if (_cub3d->rotation_angle > 0)
		_cub3d->rotation_angle = _cub3d->rotation_angle % 360;
	if (_cub3d->rotation_angle <= 0)
		_cub3d->rotation_angle = (360 + _cub3d->rotation_angle) % 360;
	dest.x += cos(_cub3d->rotation_angle * M_PI / 180) * line_lenth;
	dest.y += sin(_cub3d->rotation_angle * M_PI / 180) * line_lenth;
	draw_line(_cub3d , dest);
}

void	draw_player(t_cub3d *_cub3d, t_scale scale)
{
	int		i;
	int 	j;
	float	new_x;
	float	new_y;

	if (scale.walk)
	{
		if (_cub3d->rotation_angle > 0)
			_cub3d->rotation_angle = _cub3d->rotation_angle % 360;
		if (_cub3d->rotation_angle <= 0)
			_cub3d->rotation_angle = (360 + _cub3d->rotation_angle) % 360;
		printf("angel value: %d\n", _cub3d->rotation_angle);
		new_x = _cub3d->px + cos(_cub3d->rotation_angle * M_PI / 180) * scale.walk;
		new_y = _cub3d->py + sin(_cub3d->rotation_angle * M_PI / 180) * scale.walk;
		if (_cub3d->map[(int)new_y / PIXEL + 6][(int)new_x / PIXEL] != '1')
		{
			_cub3d->px = new_x;
			_cub3d->py = new_y;
		}
	}
	i =  -PLAYER_SIZE / 2;
	while (i < PLAYER_SIZE / 2)
	{
		j = -PLAYER_SIZE / 2;
		while (j < PLAYER_SIZE / 2)
		{
			img_pix_put(_cub3d, round(_cub3d->px + j), round(_cub3d->py + i), 0xFF0000);
			j++;
		}
		i++;
	}
}

void cub3d(t_cub3d *_cub3d)
{
	int width = 0;
	int height = 0;
	t_scale	scale;

	scale.walk = 0;
	scale.right_left = 0;
	ft_count(_cub3d, &_cub3d->width, &_cub3d->height);
	_cub3d->rotation_angle = 0;
	_cub3d->step_size = 4;
	_cub3d->mlx_ptr = mlx_init();
	_cub3d->mlx_win = mlx_new_window(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2, "cub3d");
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, &_cub3d->img.line_len, &_cub3d->img.endian);
	draw_map(_cub3d);
	draw_player(_cub3d, scale);
	draw_ray(_cub3d);
	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, width, height);
	
	mlx_hook(_cub3d->mlx_win, 2, 0, &key_hook, _cub3d);
	mlx_hook(_cub3d->mlx_win, ON_DESTROY, 0, ft_close, _cub3d);
	mlx_loop(_cub3d->mlx_ptr);
}
