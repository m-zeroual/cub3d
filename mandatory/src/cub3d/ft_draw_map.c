/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:28:12 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/15 14:56:18 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"

static void	ft_put_pixle(t_cub3d *_cub3d, char c, int x1, int y1)
{
	int	y;
	int	x;

	y = 0;
	while (y < PIXEL)
	{
		x = 0;
		while (x < PIXEL)
		{
			if (c == '1')
				img_pixl_put(_cub3d, (x1 * PIXEL) + x, \
				(y1 * PIXEL) + y, 0x808080);
			x++;
		}
		y++;
	}
}

void	ft_draw_map(t_cub3d *_cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (y < _cub3d->height)
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
