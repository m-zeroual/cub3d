/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:28:12 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/09 20:10:22 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

static void	ft_put_pixle(t_cub3d *_cub3d, char c, int x1, int y1)
{
	int	y;
	int	x;

	y = 0;
	y1 = y1 - 6;
	while (y < PIXEL)
	{
		x = 0;
		while (x < PIXEL)
		{
			if (c == '1')
				img_pixl_put(_cub3d, (x1 * PIXEL) + x, \
				(y1 * PIXEL) + y, 0x808080);
			if (c == 'D')
				img_pixl_put(_cub3d, (x1 * PIXEL) + x, \
				(y1 * PIXEL) + y, 0x2F435A);
			x++;
		}
		y++;
	}
}

void	ft_draw_map(t_cub3d *_cub3d)
{
	int	y;
	int	x;

	y = 6;
	while (y < _cub3d->height + 6)
	{
		x = 0;
		while (x < _cub3d->width)
		{
			if (_cub3d->map[y][x] == '1' && x <= (int)ft_strlen(_cub3d->map[y]))
				ft_put_pixle(_cub3d, '1', x, y);
			else if (_cub3d->map[y][x] == 'D' && \
			x <= (int)ft_strlen(_cub3d->map[y]))
				ft_put_pixle(_cub3d, 'D', x, y);
			else if (_cub3d->map[y][x] == 'O' && \
			x <= (int)ft_strlen(_cub3d->map[y]))
				ft_put_pixle(_cub3d, 'O', x, y);
			ft_put_pixle(_cub3d, '0', x, y);
			x++;
		}
		y++;
	}
}
