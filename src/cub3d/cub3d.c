/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:53:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/23 14:24:15 by mzeroual         ###   ########.fr       */
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

void	img_pix_put(t_cub3d *_cub3d, int x, int y, int color)
{
	char    *pixel;

    pixel = _cub3d->img.addr + (y * _cub3d->img.line_len + x * (_cub3d->img.bpp / 8));
	*(int *)pixel = color;
}

void ft_put_player(t_cub3d *_cub3d, int x1, int y1)
{
	int x;
	int y;
	int l;

	y = 0;
	l = 1;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			img_pix_put(_cub3d, x1 + x, y1 + y, 0xFF0000);
			x++;
		}
		y++;
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

void ft_draw_map(t_cub3d *_cub3d)
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

void	ft_update_player(t_cub3d *_cub3d)
{
	(void)_cub3d;
	_cub3d->px -= 3; 
}

// void left(t_cub3d *_cub3d)
// {
// 	// ft_update_player(_cub3d);
// }

// void up(t_cub3d *_cub3d)
// {
// 	_cub3d->py -= 5;
// }


int	key_hook(int keyCode, t_cub3d *_cub3d)
{
	(void)_cub3d;
	if (keyCode == 123)
	{
		_cub3d->turn_direction = -1;
		printf("left\n");
	}
	if (keyCode == 124)
	{
		_cub3d->turn_direction = 1;
		printf("right\n");
	}
	if (keyCode == 125)
	{
		printf("down\n");
	}
	if (keyCode == 126)
	{
		// up(_cub3d);
		printf("up\n");
	}
	return (0);
}

int	quit(void)
{
	exit(0);
	return (0);
}

void	ft_draw_player(t_cub3d *_cub3d)
{
	printf("PPOS(%d,%d)\n", _cub3d->px, _cub3d->py);
	ft_put_player(_cub3d, _cub3d->px - 25,  _cub3d->py - 25);


}

void cub3d(t_cub3d *_cub3d)
{
	int width = 0;
	int height = 0;


	_cub3d->turn_direction = 0;
	_cub3d->player_facing = M_PI / 2;
	_cub3d->rotation_speed = 2 * (M_PI / 180);
	printf("%f\n", M_PI);
	printf("%f\n", M_PI / 180);
	ft_count(_cub3d, &_cub3d->width, &_cub3d->height);
	_cub3d->mlx_ptr = mlx_init();
	_cub3d->mlx_win = mlx_new_window(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2, "cub3d");
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, &_cub3d->img.line_len, &_cub3d->img.endian);
	ft_draw_map(_cub3d);
	ft_draw_player(_cub3d);
	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, width, height);
	// mlx_key_hook(_cub3d->mlx_win, key_hook, _cub3d);

	mlx_hook(_cub3d->mlx_win, 2, 0, key_hook, _cub3d);
	mlx_hook(_cub3d->mlx_win, 17, 0, quit, _cub3d);
	
	// ft_display(_cub3d->map);
	_cub3d->turn_direction = 0;
	mlx_loop(_cub3d->mlx_ptr);
}
