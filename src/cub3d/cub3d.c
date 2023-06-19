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

void ft_count(char **map, int *lines, int *max)
{
	int i;
	int j;

	i = 6;
	*max = 0;
	*lines = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (*max < j)
			*max = j;
		(*lines)++;
		i++;
	}
	(*lines)--;
	(*max)++;
}

// void ft_pixle(t_cub3d *_cub3d, char c, int i1, int j1)
// {
// 	int i;
// 	int j;

// 	(void)i1;
// 	(void)j1;
// 	// (void)c;

// 	i = 0;
// 	i1 = i1 - 6;
// 	while (i <= 39)
// 	{
// 		j = 0;
// 		while (j <= 39)
// 		{
// 			if (c == '1')
// 				mlx_pixel_put(_cub3d->mlx_ptr, _cub3d->mlx_win, (j1 * 40) + (j + 1), (i1 * 40) + (i + 1), 0x808080);
// 			if (c != '1')
// 				mlx_pixel_put(_cub3d->mlx_ptr, _cub3d->mlx_win, (j1 * 40) + (j + 1), (i1 * 40) + (i + 1), 0xF0FFFF);
// 			mlx_pixel_put(_cub3d->mlx_ptr, _cub3d->mlx_win, (j1 * 40) + j, i1 * 40, 0x0000FF);
// 			j++;
// 		}
// 		mlx_pixel_put(_cub3d->mlx_ptr, _cub3d->mlx_win, (j1 * 40) + j, (i1 * 40) + i, 0x0000FF);
// 		i++;
// 	}
// }

void	img_pix_put(t_cub3d *_cub3d, int x, int y, int color)
{
	char    *pixel;

    pixel = _cub3d->img.addr + (y * _cub3d->img.line_len + x * (_cub3d->img.bpp / 8));
	*(int *)pixel = color;
}

// void	img_pix_put(t_cub3d *_cub3d, int x, int y, int color)
// {
// 	char    *pixel;
// 	int		i;

// 	i = _cub3d->img.bpp - 8;
//     pixel = _cub3d->img.addr + (y * _cub3d->img.line_len + x * (_cub3d->img.bpp / 8));
// 	while (i >= 0)
// 	{
// 		/* big endian, MSB is the leftmost bit */
// 		if (_cub3d->img.endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		/* little endian, LSB is the leftmost bit */
// 		else
// 			*pixel++ = (color >> (_cub3d->img.bpp - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }

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
	while (y < PIXEL - 1)
	{
		x = 0;
		while (x < PIXEL - 1)
		{
			if (c == '1')
				img_pix_put(_cub3d, (x1 * PIXEL) + (x + 1), (y1 * PIXEL) + (y + 1), 0x808080);
			else
				img_pix_put(_cub3d, (x1 * PIXEL) + (x + 1), (y1 * PIXEL) + (y + 1), 0xF0FFFF);
			img_pix_put(_cub3d, (x1 * PIXEL) + x, y1 * PIXEL, 0x0000FF);
			x++;
		}
		// if (x1 == 0)
		// 	img_pix_put(_cub3d, (x1 * PIXEL), (y1 * PIXEL) + y, 0x0000FF);
		img_pix_put(_cub3d, (x1 * PIXEL), (y1 * PIXEL) + y, 0x0000FF);
		y++;
	}
}

void ft_drow(t_cub3d *_cub3d)
{
	int y;
	int x;

	y = 6;
	while (_cub3d->map[y])
	{
		x = 0;
		while (_cub3d->map[y][x])
		{
			if (_cub3d->map[y][x] == '1')
				ft_pixle(_cub3d, '1', x, y);

			else if (_cub3d->map[y][x] != '1')
				ft_pixle(_cub3d, '0', x, y);
			printf("%c", _cub3d->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void cub3d(t_cub3d *_cub3d)
{
	int width = 0;
	int height = 0;

	ft_count(_cub3d->map, &_cub3d->width, &_cub3d->height);
	_cub3d->mlx_ptr = mlx_init();
	_cub3d->mlx_win = mlx_new_window(_cub3d->mlx_ptr, _cub3d->width * PIXEL, _cub3d->height * PIXEL, "cub3d");
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, _cub3d->width * PIXEL, _cub3d->height * PIXEL);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, &_cub3d->img.line_len, &_cub3d->img.endian);
	ft_drow(_cub3d);

	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, width, height);
	
	// ft_display(_cub3d->map);
	mlx_loop(_cub3d->mlx_ptr);
}
