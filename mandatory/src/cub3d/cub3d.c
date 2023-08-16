/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:53:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/16 09:38:48 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"

static void	ft_count(t_cub3d *_cub3d, int *width, int *height)
{
	int	i;
	int	j;

	i = 0;
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
				_cub3d->py = (i * PIXEL) + (PIXEL / 2);
			}
			j++;
		}
		if (*width < j)
			*width = j;
		(*height)++;
		i++;
	}
}

static int	initial_direction(t_cub3d *_cub3d)
{
	if (_cub3d->map[(int)(_cub3d->py / PIXEL)] \
	[(int)(_cub3d->px / PIXEL)] == 'N')
		return (90);
	else if (_cub3d->map[(int)(_cub3d->py / PIXEL)] \
	[(int)(_cub3d->px / PIXEL)] == 'S')
		return (270);
	else if (_cub3d->map[(int)(_cub3d->py / PIXEL)] \
	[(int)(_cub3d->px / PIXEL)] == 'E')
		return (0);
	else
		return (180);
}

void	ft_draw(t_cub3d *_cub3d)
{
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, WIDTH, HEIGHT);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, \
	&_cub3d->img.line_len, &_cub3d->img.endian);
	_cub3d->rotation = normalize_angle(_cub3d->rotation);
	cast_all_rays(_cub3d);
	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, \
	_cub3d->img.mlx_img, 0, 0);
	mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->img.mlx_img);
}

void	cub3d(t_cub3d *_cub3d)
{
	ft_count(_cub3d, &_cub3d->width, &_cub3d->height);
	_cub3d->mlx_ptr = mlx_init();
	open_textures(_cub3d);
	_cub3d->mlx_win = mlx_new_window(_cub3d->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	_cub3d->rotation = initial_direction(_cub3d);
	ft_draw(_cub3d);
	mlx_hook(_cub3d->mlx_win, ON_KEY_PRESS, 0, key_hook, _cub3d);
	mlx_hook(_cub3d->mlx_win, ON_DESTROY, 0, quit, _cub3d);
	mlx_loop(_cub3d->mlx_ptr);
}
