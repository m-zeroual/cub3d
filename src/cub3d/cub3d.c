/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:53:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/07/28 14:34:17 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

static void ft_draw_ray(t_cub3d *_cub3d)
{
	int ppx = _cub3d->px;
	int ppy = _cub3d->py;
	int sx;
	int sy;
	int dx = abs(_cub3d->endx - ppx);
	if (ppx < _cub3d->endx)
		sx = 1;
	else
		sx = -1;
	int dy = abs(_cub3d->endy - ppy) * -1;

	if (ppy < _cub3d->endy)
		sy = 1;
	else
		sy = -1;
	int error = dx + dy;
	// printf("sx:%d\tsy:%d\n", sx, sy);
//-------------
	int e2 = 0;
	while (1)
	{
		// printf("x:%d\ty:%d\n", ppx, ppy);
		img_pixl_put(_cub3d, ppx, ppy, 0x00FFFF);
		// break ;
		if (_cub3d->endx == ppx && _cub3d->endy == ppy)
			break ;

		e2 = 2 * error;
		if (e2 >= dy)
		{
		if (ppx == _cub3d->endx)
				break ;
			error = error + dy;
			ppx = ppx + sx;
		}

		if (e2 <= dx)
		{
			if (ppy == _cub3d->endy)
				break ;
			error = error + dx;
			ppy = ppy + sy;
		}

	}
}

static void ft_count(t_cub3d *_cub3d, int *width, int *height)
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


void ft_put_player(t_cub3d *_cub3d, int x1, int y1)
{
	int x;
	int y;
	int l;

	y = -(6 / 2);
	l = 1;
	while (y < 6 / 2)
	{
		x = -(6 / 2);
		while (x < 6 / 2)
		{
			img_pixl_put(_cub3d, x1 + x, y1 + y, 0xFF0000);
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

int	quit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_draw_player(t_cub3d *_cub3d)
{
	printf("PPOS(%d,%d)\n", _cub3d->px, _cub3d->py);
	ft_put_player(_cub3d, _cub3d->px,  _cub3d->py);
}



void ft_rotation(t_cub3d *_cub3d)
{

	// printf("==> endx:%d\tendy:%d\n", _cub3d->endx, _cub3d->endy);
	if (_cub3d->rotation > 0)
		_cub3d->rotation = _cub3d->rotation % 360;
	if (_cub3d->rotation < 0)
		_cub3d->rotation = (360 + _cub3d->rotation) % 360;
		
	_cub3d->endx = _cub3d->px + cos(_cub3d->rotation * M_PI / 180) * 25;
	_cub3d->endy = _cub3d->py + -sin(_cub3d->rotation * M_PI / 180) * 25;
	// if (rotation)
	// {
	// 	_cub3d->rotation = _cub3d->rotation - 10 * M_PI / 180;
	// 	// if (_cub3d->rotation >= 360 * M_PI / 180)
	// 	// 	_cub3d->rotation = 10 * M_PI / 180;
	// 	_cub3d->endx = _cub3d->px + cos(_cub3d->rotation) * 25;
	// 	_cub3d->endy = _cub3d->py + sin(_cub3d->rotation) * 25;
	// }
	// else
	// {
	// 	_cub3d->rotation += 10 * M_PI / 180;
	// 	// if (_cub3d->rotation > 360 * M_PI / 180)
	// 	// 	_cub3d->rotation = 10 * M_PI / 180;

	// 	_cub3d->endx = _cub3d->px + cos(_cub3d->rotation) * 25;
	// 	_cub3d->endy = _cub3d->py + sin(_cub3d->rotation) * 25;
	// }
	// printf("endx:%d\tendy:%d\n", _cub3d->endx, _cub3d->endy);
	printf("%f\n", _cub3d->rotation * M_PI / 180);
	
}
int ft_draw(t_cub3d *_cub3d)
{
	int width = 0, height = 0;
	// _cub3d->endx = _cub3d->px;
	// _cub3d->endy = _cub3d->py;
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, &_cub3d->img.line_len, &_cub3d->img.endian);
	ft_rotation(_cub3d);
	ft_draw_map(_cub3d);
	ft_draw_player(_cub3d);
	ft_draw_ray(_cub3d);
	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, width, height);
	// mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->mlx_win);


	return (0);
}

int	key_hook(int keyCode, t_cub3d *_cub3d)
{
	// int width = 0;
	// int height = 0;
	(void)_cub3d;
	if (keyCode == 123)
	{
		// ft_rotation(_cub3d, 1);
		_cub3d->rotation += 10;
		printf("left\n");
	}
	if (keyCode == 124)
	{
		// ft_rotation(_cub3d, 0);
		_cub3d->rotation -= 10;
		printf("right\n");
	}
	if (keyCode == 125)
	{
		printf("----------down---------\n");
		// _cub3d->py += 5;
		_cub3d->px -= cos(_cub3d->rotation * M_PI / 180) * 4;
		_cub3d->py -= -sin(_cub3d->rotation * M_PI / 180) * 4;

	}
	if (keyCode == 126)
	{
		// up(_cub3d);
		// _cub3d->py -= 5;
		_cub3d->px += cos(_cub3d->rotation * M_PI / 180) * 4;
		_cub3d->py += -sin(_cub3d->rotation * M_PI / 180) * 4;
		
		printf("%f\n" , _cub3d->py + -sin(_cub3d->rotation * M_PI / 180) * 4);
		printf("--------up--------\n");
	}
	if (keyCode == 53)
		quit();
	// mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->mlx_win);
	// printf("= %d\n", mlx_clear_window(_cub3d->mlx_ptr, _cub3d->mlx_win));
	// mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->img.mlx_img);
	// ft_draw(_cub3d);
	return (0);
}








void cub3d(t_cub3d *_cub3d)
{
	
	ft_count(_cub3d, &_cub3d->width, &_cub3d->height);
	_cub3d->mlx_ptr = mlx_init();
	_cub3d->mlx_win = mlx_new_window(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2, "cub3d");
	_cub3d->rotation = 0;
	// _cub3d->endx = _cub3d->px + cos(_cub3d->rotation) * 25;
	// _cub3d->endy = _cub3d->py + sin(_cub3d->rotation) * 25;
	// printf("endx;%d\tendy%d\n", _cub3d->endx, _cub3d->endy);
	// mlx_loop_hook(_cub3d->mlx_ptr, ft_draw, (void *)_cub3d);
	// mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, width, height);
	
	// ft_draw(_cub3d);
	mlx_loop_hook(_cub3d->mlx_ptr, ft_draw, _cub3d);
	mlx_hook(_cub3d->mlx_win, 2, 0, key_hook, _cub3d);
	mlx_hook(_cub3d->mlx_win, 17, 0, quit, _cub3d);
	// ft_display(_cub3d->map);
	mlx_loop(_cub3d->mlx_ptr);
}
