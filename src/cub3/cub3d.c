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

void ft_pixle(t_cub3d *_cub3d, char c, int i1, int j1)
{
	int i;
	int j;

	(void)i1;
	(void)j1;
	// (void)c;

	i = 0;
	i1 = i1 - 6;
	while (i <= 39)
	{
		j = 0;
		while (j <= 39)
		{
			if (c == '1')
				mlx_pixel_put(_cub3d->mlx_ptr, _cub3d->mlx_win, (j1 * 40) + (j + 1), (i1 * 40) + (i + 1), 0x808080);
			if (c != '1')
				mlx_pixel_put(_cub3d->mlx_ptr, _cub3d->mlx_win, (j1 * 40) + (j + 1), (i1 * 40) + (i + 1), 0xF0FFFF);
			mlx_pixel_put(_cub3d->mlx_ptr, _cub3d->mlx_win, (j1 * 40) + j, i1 * 40, 0x0000FF);
			j++;
		}
		mlx_pixel_put(_cub3d->mlx_ptr, _cub3d->mlx_win, (j1 * 40) + j, (i1 * 40) + i, 0x0000FF);
		i++;
	}
}

void ft_drow(t_cub3d *_cub3d)
{
	int i;
	int j;

	i = 6;
	while (_cub3d->map[i])
	{
		j = 0;
		while (_cub3d->map[i][j])
		{
			if (_cub3d->map[i][j] == '1')
				ft_pixle(_cub3d, '1', i, j);
			else if (_cub3d->map[i][j] != '1')
				ft_pixle(_cub3d, '0', i, j);
			j++;
		}
		i++;
	}
}

void cub3d(t_cub3d *_cub3d)
{
	
	ft_count(_cub3d->map, &_cub3d->lines, &_cub3d->max);
	_cub3d->mlx_ptr = mlx_init();
	_cub3d->mlx_win = mlx_new_window(_cub3d->mlx_ptr, _cub3d->lines * 40, _cub3d->max * 40, "cub3d");

	ft_drow(_cub3d);
	
	ft_display(_cub3d->map);
	mlx_loop(_cub3d->mlx_ptr);

}
