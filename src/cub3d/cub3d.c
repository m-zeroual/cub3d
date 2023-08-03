/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:53:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/03 17:02:35 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

int vetagorc(int x1, int y1, int x, int y)
{
	return(sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)));
}

void ft_draw_ray(t_cub3d *_cub3d, int endx, int endy, int color)
{
	int i;

	i = 0;
    int dx = endx - _cub3d->px;
    int dy = endy - _cub3d->py;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = _cub3d->px;
    float y = _cub3d->py;

    while (i <= steps) 
	{
		if (x >= 0 && x < _cub3d->width * PIXEL && y >= 0 && y < _cub3d->height * PIXEL)
			img_pixl_put(_cub3d, (int)x, (int)y, color);
        x += xIncrement;
        y += yIncrement;
		i++;
    }
}



void ft_check_view(t_cub3d *_cub3d)
{
	if (_cub3d->ray_angle > 0 && _cub3d->ray_angle <= 180)
		_cub3d->up_down = UP;
	else
		_cub3d->up_down = DOWN;

	if (_cub3d->ray_angle >= 90 && _cub3d->ray_angle < 270)
		_cub3d->left_right = LEFT;
	else 
		_cub3d->left_right = RIGHT;
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



int	quit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_draw_player(t_cub3d *_cub3d)
{
	// printf("PPOS(%d,%d)\n", _cub3d->px, _cub3d->py);
	ft_put_player(_cub3d, _cub3d->px,  _cub3d->py);
}



void ft_rotation(t_cub3d *_cub3d)
{

	if (_cub3d->rotation > 0)
		_cub3d->rotation = _cub3d->rotation % 360;
	if (_cub3d->rotation < 0)
		_cub3d->rotation = (360 + _cub3d->rotation) % 360;
	
	// _cub3d->vertical.x = _cub3d->px + cos(_cub3d->rotation * M_PI / 180) * 25;
	// _cub3d->vertical.y = _cub3d->py + -sin(_cub3d->rotation * M_PI / 180) * 25;
}

// void	draw_player(t_cub3d *_cub3d)
// {
// 	int		i;
// 	int 	j;
// 	float	new_x;
// 	float	new_y;

// 	if (_cub3d->rotation > 0)
// 		_cub3d->rotation = _cub3d->rotation % 360;
// 	if (_cub3d->rotation <= 0)
// 		_cub3d->rotation = (360 + _cub3d->rotation) % 360;
// 	// printf("angel value: %d\n", _cub3d->rotation);
// 	new_x = _cub3d->px;
// 	new_y = _cub3d->py;
// 	// new_x = _cub3d->px + cos(_cub3d->rotation * M_PI / 180) * 1;
// 	// new_y = _cub3d->py - sin(_cub3d->rotation * M_PI / 180) * 1;
// 	if (_cub3d->map[(int)(new_y / PIXEL) + 6][(int)((new_x + (PLAYER_SIZE / 2)) / PIXEL)] != '1' && 
// 	_cub3d->map[(int)(new_y / PIXEL) + 6][(int)((new_x - (PLAYER_SIZE / 2)) / PIXEL)] != '1' && 
// 	_cub3d->map[(int)((new_y - (PLAYER_SIZE / 2)) / PIXEL) + 6][(int)(new_x / PIXEL)] != '1' &&
// 	_cub3d->map[(int)((new_y + (PLAYER_SIZE / 2)) / PIXEL) + 6][(int)(new_x / PIXEL)] != '1')
// 	{
// 		_cub3d->px = new_x;
// 		_cub3d->py = new_y;
// 	}
// 	i =  -PLAYER_SIZE / 2;
// 	while (i < PLAYER_SIZE / 2)
// 	{
// 		j = -PLAYER_SIZE / 2;
// 		while (j < PLAYER_SIZE / 2)
// 		{
// 			img_pixl_put(_cub3d, (int)(_cub3d->px + j), (int)(_cub3d->py + i), 0xFF0000);
// 			j++;
// 		}
// 		i++;
// 	}
// }

int	initial_direction(t_cub3d *_cub3d)
{
	if (_cub3d->map[(int)(_cub3d->py / PIXEL) + 6][(int)(_cub3d->px / PIXEL)] == 'N')
		return (90);
	else if (_cub3d->map[(int)(_cub3d->py / PIXEL) + 6][(int)(_cub3d->px / PIXEL)] == 'S')
		return (270);
	else if (_cub3d->map[(int)(_cub3d->py / PIXEL) + 6][(int)(_cub3d->px / PIXEL)] == 'E')
		return (0);
	else
		return (180);	
}


int ft_calcul_h(t_cub3d *_cub3d)
{
	int check = 0;
	// int check_left = 0;
	if (_cub3d->up_down)
		_cub3d->start.y = (int)(_cub3d->py / PIXEL) * PIXEL;
	else
		_cub3d->start.y = (int)(_cub3d->py / PIXEL) * PIXEL + PIXEL;
	_cub3d->start.x = _cub3d->px + ((_cub3d->py - _cub3d->start.y) / tan(_cub3d->ray_angle * M_PI / 180));
	_cub3d->step.y = PIXEL;
	if(_cub3d->up_down)
		_cub3d->step.y *= -1;
	_cub3d->step.x =  _cub3d->step.y / tan(_cub3d->ray_angle * M_PI / 180);
	if (_cub3d->left_right && _cub3d->step.x < 0)
		_cub3d->step.x *= -1;
	if (!_cub3d->left_right && _cub3d->step.x > 0)
		_cub3d->step.x *= -1;
	// printf("left_right == %d\n", _cub3d->left_right);
	if (_cub3d->up_down)
		check = 1;
	// if (!_cub3d->left_right)
	// 	check_left = 1;
	_cub3d->horizontal.y = _cub3d->start.y;
	_cub3d->horizontal.x = _cub3d->start.x;
	while (((int)(_cub3d->horizontal.x / PIXEL) >= 0 && (int)(_cub3d->horizontal.x / PIXEL) < _cub3d->width)
		&& (((int)_cub3d->horizontal.y / PIXEL) - check >= 0 &&  (int)(_cub3d->horizontal.y / PIXEL) - check < _cub3d->height)
		)
	{
		
		if (_cub3d->map[(int)(((_cub3d->horizontal.y) - check) / PIXEL) + 6][(int)((_cub3d->horizontal.x) / PIXEL)] == '1')
			break ;
		_cub3d->horizontal.y += _cub3d->step.y;
		_cub3d->horizontal.x += _cub3d->step.x;
	}
	// printf("-------------H------------\n");
	// printf("up_down\t(%d)\n", _cub3d->up_down);
	// printf("rotation\t(%d)\n",_cub3d->rotation);
	// printf("Player\t\t(%f, %f)\n", _cub3d->px, _cub3d->py);
	// printf("Start\t\t(%f, %f)\n", _cub3d->start.x, _cub3d->start.y);
	// printf("Step \t\t(%f, %f)\n", _cub3d->step.x, _cub3d->step.y);
	// printf("horizontal \t(%f, %f)\n", _cub3d->horizontal.x, _cub3d->horizontal.y);
	// ft_draw_ray(_cub3d, (int)_cub3d->horizontal.x, (int)_cub3d->horizontal.y, 0x00FF00);
	return (vetagorc(_cub3d->horizontal.x, _cub3d->horizontal.y, _cub3d->px, _cub3d->py));
}

int ft_calcul_v(t_cub3d *_cub3d)
{
	int check = 0;
	if (_cub3d->left_right)
		_cub3d->start.x = (int)(_cub3d->px / PIXEL) * PIXEL + PIXEL;
	else
		_cub3d->start.x = (int)(_cub3d->px / PIXEL) * PIXEL;
	_cub3d->start.y = _cub3d->py + ((_cub3d->px - _cub3d->start.x) * tan(_cub3d->ray_angle * M_PI / 180));

	_cub3d->step.x = PIXEL;
	if(!_cub3d->left_right)
		_cub3d->step.x *= -1;
	_cub3d->step.y =  _cub3d->step.x * tan(_cub3d->ray_angle * M_PI / 180);

	if (_cub3d->up_down && _cub3d->step.y > 0)
		_cub3d->step.y *= -1;

	if (!_cub3d->up_down && _cub3d->step.y < 0)
		_cub3d->step.y *= -1;
	if (!_cub3d->left_right)
		check = 1;
	_cub3d->vertical.y = _cub3d->start.y;
	_cub3d->vertical.x = _cub3d->start.x;
	while (((int)(_cub3d->vertical.x / PIXEL) - check >= 0 && (int)(_cub3d->vertical.x / PIXEL) - check < _cub3d->width)
		&& (((int)_cub3d->vertical.y / PIXEL) >= 0 &&  (int)(_cub3d->vertical.y / PIXEL) < _cub3d->height)
		)
	{
	// 	printf("%d %d\n", (int)(((_cub3d->vertical.y) - check) / PIXEL) + 6, (int)(_cub3d->vertical.x / PIXEL));
	// 	printf("%s\n", _cub3d->map[(int)(((_cub3d->vertical.y) - check) / PIXEL) + 6]);
		if (_cub3d->map[(int)((_cub3d->vertical.y) / PIXEL) + 6][(((int)(_cub3d->vertical.x) - check) / PIXEL)] == '1')
			break ;
		_cub3d->vertical.y += _cub3d->step.y;
		_cub3d->vertical.x += _cub3d->step.x;
	}
	// printf("-------------V------------\n");
	// printf("left_right\t(%d)\n", _cub3d->left_right);
	// printf("Player\t\t(%f, %f)\n", _cub3d->px, _cub3d->py);
	// printf("Start\t\t(%f, %f)\n", _cub3d->start.x, _cub3d->start.y);
	// printf("Step \t\t(%f, %f)\n", _cub3d->step.x, _cub3d->step.y);
	// printf("vertical \t(%f, %f)\n", _cub3d->vertical.x, _cub3d->vertical.y);
	// ft_draw_ray(_cub3d, (int)_cub3d->vertical.x, (int)_cub3d->vertical.y, 0x00FF00);
	return (vetagorc(_cub3d->vertical.x, _cub3d->vertical.y, _cub3d->px, _cub3d->py));
}

void ft_raycating(t_cub3d *_cub3d)
{
	// printf("---------------------------------------------\n");
	ft_check_view(_cub3d);

	int dy = ft_calcul_h(_cub3d);
	// printf("dy %d\n", dy);
	int dx = ft_calcul_v(_cub3d);
	// printf("dx %d\n", dx);
	// printf("rotation\t(%d)\ni == \t(%d)\n",_cub3d->ray_angle, i);
	// printf("---------------------------------------------\n");
	if (dy < dx)
	{
		ft_draw_ray(_cub3d, _cub3d->horizontal.x, _cub3d->horizontal.y, 0x00FF00);
		printf("=>\thorizontal\n");
	}
	else
	{
		ft_draw_ray(_cub3d, _cub3d->vertical.x, _cub3d->vertical.y, 0x00FF00);
		printf("=>\tvertical\n");
	}
}

void cast_all_rays(t_cub3d *_cub3d)
{
	int	i;

	i = 0;
	_cub3d->ray_angle = _cub3d->rotation - 30;
	// printf("\n\n\n =>>>>>>>> before %d\n", _cub3d->ray_angle);
	// while (i < _cub3d->width * PIXEL)
	// printf("%d\n",_cub3d->width * PIXEL);
	while (i < (_cub3d->width * PIXEL))
	{
		if (_cub3d->ray_angle > 0)
			_cub3d->ray_angle = fmodf(_cub3d->ray_angle, 360);
			// _cub3d->ray_angle = _cub3d->ray_angle % 360;
		if (_cub3d->ray_angle < 0)
			_cub3d->ray_angle = fmodf((360 + _cub3d->ray_angle), 360);
		ft_raycating(_cub3d);
		// printf("\n ====> inside %d\n", _cub3d->ray_angle);
		_cub3d->ray_angle += 60 / (float)(_cub3d->width * PIXEL);
		i += 1;
	}
	// printf("after %d\n", _cub3d->ray_angle);
}

int ft_draw(t_cub3d *_cub3d)
{
	int width = 0, height = 0;
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, &_cub3d->img.line_len, &_cub3d->img.endian);
	ft_rotation(_cub3d);
	ft_draw_map(_cub3d);
	ft_draw_player(_cub3d);
	cast_all_rays(_cub3d);
	// ft_raycating(_cub3d);
	// _cub3d->rotation -=30;
	// ft_raycating(_cub3d);
	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, width, height);
	// sleep(1);
	mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->img.mlx_img);
	return (0);
}

int	key_hook(int keyCode, t_cub3d *_cub3d)
{
	(void)_cub3d;
	if (keyCode == 123)
	{
		printf("----------left---------\n");
		_cub3d->rotation += 3;
	}
	if (keyCode == 124)
	{
		printf("----------right---------\n");
		_cub3d->rotation -= 3;
	}
	if (keyCode == 125)
	{
		printf("----------down---------\n");
		_cub3d->px -= cos(_cub3d->rotation * M_PI / 180) * 5;
		_cub3d->py -= -sin(_cub3d->rotation * M_PI / 180) * 5;
	}
	if (keyCode == 126)
	{
		printf("--------up--------\n");
		_cub3d->px += cos(_cub3d->rotation * M_PI / 180) * 5;
		_cub3d->py += -sin(_cub3d->rotation * M_PI / 180) * 5;
	}
	if (keyCode == 53)
		quit();
	return (0);
}








void cub3d(t_cub3d *_cub3d)
{
	
	ft_count(_cub3d, &_cub3d->width, &_cub3d->height);
	_cub3d->mlx_ptr = mlx_init();
	_cub3d->mlx_win = mlx_new_window(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2, "cub3d");
	// _cub3d->rotation = 180;
	_cub3d->rotation = initial_direction(_cub3d);
	mlx_loop_hook(_cub3d->mlx_ptr, ft_draw, _cub3d);
	mlx_hook(_cub3d->mlx_win, 2, 0, key_hook, _cub3d);
	mlx_hook(_cub3d->mlx_win, 17, 0, quit, _cub3d);
	mlx_loop(_cub3d->mlx_ptr);
}
