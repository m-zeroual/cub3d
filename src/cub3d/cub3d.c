/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:53:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/17 17:53:47 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void ft_count(char **map, int *width, int *height)
{
	int i;
	int j;

	i = 6;
	*width = 0;
	*height = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
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

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			img_pix_put(_cub3d, x1 + x, y1 + y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void ft_pixle(t_cub3d *_cub3d, char c, int x1, int y1)
{
	int y;
	int x;

	(void)x;
	(void)x1;
	(void)y;
	(void)c;

	y = 0;
	y1 = y1 - 6;
	while (y < PIXEL)
	{
		x = 0;
		while (x < PIXEL)
		{
			if (c == '1')
				img_pix_put(_cub3d, (x1 * PIXEL) + (x ), (y1 * PIXEL) + (y), 0x808080);
			else if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
				ft_put_player(_cub3d, ((x1 + 1) * PIXEL) - (PIXEL/2), ((y1 + 1) * PIXEL) - (PIXEL/2));
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

void ft_draw(t_cub3d *_cub3d)
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
				ft_pixle(_cub3d, '1', x, y);
			else if ((_cub3d->map[y][x] == 'W' || _cub3d->map[y][x] == 'N'
				|| _cub3d->map[y][x] == 'E' || _cub3d->map[y][x] == 'S')
				&& x <= (int)ft_strlen(_cub3d->map[y]))
				ft_pixle(_cub3d, _cub3d->map[y][x], x, y);
			else
				ft_pixle(_cub3d, '0', x, y);
			x++;
		}
		y++;
	}
}

void left()
{

}

// int	key_hook(int keycode, t_cub3d *_cub3d)
// {
// 	(void)keycode;
// 	(void)_cub3d;

// 	if (keycode == 123)
// 	{
// 		left();	
// 		printf("left\n");
// 	}
// 	if (keycode == 124)
// 		printf("right\n");
// 	if (keycode == 125)
// 		printf("down\n");
// 	if (keycode == 126)
// 		printf("up\n");
// 	return (0);
// }

int	key_hook(void *_cub3d)
{
	(void)_cub3d;
	return (0);
}

void cub3d(t_cub3d *_cub3d)
{
	int width = 0;
	int height = 0;

	ft_count(_cub3d->map, &_cub3d->width, &_cub3d->height);
	printf("width %d height %d\n", _cub3d->width, _cub3d->height);
	_cub3d->mlx_ptr = mlx_init();
	_cub3d->mlx_win = mlx_new_window(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2, "cub3d");
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, &_cub3d->img.line_len, &_cub3d->img.endian);
	ft_draw(_cub3d);
	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, width, height);
	// mlx_key_hook(_cub3d->mlx_win, key_hook, _cub3d);
	mlx_loop_hook(_cub3d->mlx_ptr, key_hook, _cub3d);
	
	// ft_display(_cub3d->map);
	mlx_loop(_cub3d->mlx_ptr);
}
