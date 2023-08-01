/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:53:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/01 16:49:50 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

int vetagorc(int x1, int y1, int x, int y)
{
	return(sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)));
}

void ft_draw_ray(t_cub3d *_cub3d, int endx, int endy, int color)
{
    int dx = endx - _cub3d->px;
    int dy = endy - _cub3d->py;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = _cub3d->px;
    float y = _cub3d->py;

    for (int i = 0; i <= steps; i++) {
		img_pixl_put(_cub3d, (int)x, (int)y, color);
        x += xIncrement;
        y += yIncrement;
    }
}



// void ft_calcul_start_piont_and_step_H(t_cub3d *_cub3d)
// {
// 	if (_cub3d->up_down)
// 		_cub3d->starty = (((int)(_cub3d->py / 50) * 50));
// 	else
// 		_cub3d->starty = (((int)(_cub3d->py / 50) * 50) + 50);
// 	_cub3d->startx = _cub3d->px + ((_cub3d->py - _cub3d->starty) / tan(_cub3d->rotation * M_PI / 180));

// 	_cub3d->stepy = 50;
// 	_cub3d->stepx = (_cub3d->stepy / tan(_cub3d->rotation * M_PI / 180));
// 	printf("------------H-----------\n");
// 	printf("|L_R = %d|\n|U_D = %d|\n", _cub3d->left_right, _cub3d->up_down);
// 	printf("Angle C˚==> %d\n", _cub3d->rotation);
// 	printf("Tan     ==> %f\n", tan(_cub3d->rotation * M_PI / 180));
// 	printf("start   ==> (%f, %f)\n", _cub3d->startx, _cub3d->starty);
// 	printf("step    ==> (%f, %f)\n", _cub3d->stepx, _cub3d->stepy);
// 	// ft_display_map(_cub3d->map);
// }




// float ft_calcul_horizontal(t_cub3d *_cub3d)
// {
// 	ft_calcul_start_piont_and_step_H(_cub3d);
// 	_cub3d->endy = _cub3d->starty;
// 	_cub3d->endx = _cub3d->startx;
// 	int check = 0;
// 	while (1)
// 	{
// 		if (_cub3d->up_down)
// 			check = _cub3d->endy - 1;
// 		else
// 			check = _cub3d->endy;
// 		if (((int)(_cub3d->endx) < 0 ||  (int)(_cub3d->endx) > (_cub3d->width * PIXEL))
// 		|| ((int)(check) < 0 ||  (int)(check) > (_cub3d->height * PIXEL))
// 		|| _cub3d->map[(int)(check / 50) + 6][(int)(_cub3d->endx / 50)] == '1')
// 			break ;
// 		if (_cub3d->up_down)
// 			_cub3d->endy -= _cub3d->stepy;
// 		else
// 			_cub3d->endy += _cub3d->stepy;
// 		_cub3d->endx += _cub3d->stepx;
// 	}
// 	ft_draw_ray(_cub3d, _cub3d->endx, _cub3d->endy, 0x00FF00);
// 	printf("px %f py %f\n", _cub3d->px, _cub3d->py);
// 	printf("endx %f endy  %f\n", _cub3d->endx, _cub3d->endy);

// 	return (vetagorc( _cub3d->endx, _cub3d->endy, _cub3d->px, _cub3d->py ));
// }



// void ft_calcul_start_piont_and_step_V(t_cub3d *_cub3d)
// {
// 	if (_cub3d->left_right)
// 		_cub3d->startx = (((int)(_cub3d->px / 50) * 50) + 50);
// 	else
// 		_cub3d->startx = (((int)(_cub3d->px / 50) * 50));

// 	_cub3d->starty = _cub3d->py + ((_cub3d->px - _cub3d->startx) * tan(_cub3d->rotation * M_PI / 180));

// 	_cub3d->stepx = 50;
// 	_cub3d->stepy = (_cub3d->stepx * tan(_cub3d->rotation * M_PI / 180));
// 	printf("------------V-----------\n");
// 	printf("|L_R = %d|\n|U_D = %d|\n", _cub3d->left_right, _cub3d->up_down);
// 	printf("Angle C˚==> %d\n", _cub3d->rotation);
// 	printf("Tan     ==> %f\n", tan(_cub3d->rotation * M_PI / 180));
// 	printf("L_R     ==> %d\n", _cub3d->left_right);
// 	printf("start   ==> (%f, %f)\n", _cub3d->startx, _cub3d->starty);
// 	printf("step    ==> (%f, %f)\n", _cub3d->stepx, _cub3d->stepy);
// 	// ft_display_map(_cub3d->map);
// }

// float ft_calcul_vertical(t_cub3d *_cub3d)
// {
// 	ft_calcul_start_piont_and_step_V(_cub3d);
// 	_cub3d->endyv = _cub3d->starty;
// 	_cub3d->endxv = _cub3d->startx;
// 	int check = 0;
// 	printf("%f %f\n", _cub3d->endxv, _cub3d->endyv);

// 	while (1)
// 	{
// 		if (_cub3d->left_right)
// 			check = _cub3d->endxv;
// 		else
// 			check = _cub3d->endxv - 1;
// 			printf("i = %d, j = %d\n",((int)(_cub3d->endy / 50)),  (int)(check / 50));
// 			printf("|%c|\n", _cub3d->map[((int)(_cub3d->endy / 50)) + 6][(int)(check / 50)]);

// 		if ((int)(_cub3d->endyv) < 0 ||  (int)(_cub3d->endyv) > (_cub3d->height * PIXEL)
// 		|| ((int)(check) < 0 ||  (int)(check) > (_cub3d->width * PIXEL))
// 		  || _cub3d->map[((int)(_cub3d->endyv / 50)) + 6][(int)(check / 50)] == '1')
// 			break ;
// 		if (_cub3d->left_right)
// 			_cub3d->endxv += _cub3d->stepx;
// 		else
// 			_cub3d->endxv -= _cub3d->stepx;

// 		_cub3d->endyv += _cub3d->stepy;
// 		// printf("here\n");
// 	    // printf("%f %f\n", _cub3d->endxv, _cub3d->endyv);
// 	}
// 	ft_draw_ray(_cub3d, _cub3d->endxv, _cub3d->endyv, 0x00FF00);
// 	return (vetagorc(_cub3d->endxv, _cub3d->endyv, _cub3d->px, _cub3d->py));
// }

void ft_check_view(t_cub3d *_cub3d)
{
	if (_cub3d->rotation > 0 && _cub3d->rotation <= 180)
		_cub3d->up_down = UP;
	else
		_cub3d->up_down = DOWN;
	if (_cub3d->rotation >= 90 && _cub3d->rotation < 270)
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
	
	_cub3d->endx = _cub3d->px + cos(_cub3d->rotation * M_PI / 180) * 25;
	_cub3d->endy = _cub3d->py + -sin(_cub3d->rotation * M_PI / 180) * 25;
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


void ft_raycating(t_cub3d *_cub3d)
{
	ft_check_view(_cub3d);
	// ft_draw_ray(_cub3d, );
	// ft_calcul_horizontal(_cub3d);
	// ft_calcul_vertical(_cub3d);

	// float dy = ft_calcul_horizontal(_cub3d);
	// printf("%f\n", dy);
	// ft_calcul_vertical(_cub3d);
	// float dx = ft_calcul_vertical(_cub3d);
	// if (dy < dx)
	// {
	// 	ft_draw_ray(_cub3d, _cub3d->endx, _cub3d->endy, 0xFF0000);
	// 	printf("dy = %f\n", dy);
	// }
	// else
	// {
	// 	printf("dx = %f\n", dx);
	// 	ft_draw_ray(_cub3d, _cub3d->endxv, _cub3d->endyv, 0x00FF00);
	// }
}

int ft_draw(t_cub3d *_cub3d)
{
	int width = 0, height = 0;
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, &_cub3d->img.line_len, &_cub3d->img.endian);
	ft_rotation(_cub3d);
	ft_draw_map(_cub3d);
	// draw_player(_cub3d);
	ft_draw_player(_cub3d);
	ft_raycating(_cub3d);
	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, width, height);
	mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->img.mlx_img);
	return (0);
}

int	key_hook(int keyCode, t_cub3d *_cub3d)
{
	(void)_cub3d;
	if (keyCode == 123)
	{
		_cub3d->rotation += 1;
	}
	if (keyCode == 124)
	{
		_cub3d->rotation -= 1;
	}
	if (keyCode == 125)
	{
		printf("----------down---------\n");
		_cub3d->px -= cos(_cub3d->rotation * M_PI / 180) * 4;
		_cub3d->py -= -sin(_cub3d->rotation * M_PI / 180) * 4;
	}
	if (keyCode == 126)
	{
		printf("--------up--------\n");
		_cub3d->px += cos(_cub3d->rotation * M_PI / 180) * 4;
		_cub3d->py += -sin(_cub3d->rotation * M_PI / 180) * 4;
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
	_cub3d->rotation = 45;
	// _cub3d->rotation = initial_direction(_cub3d);
	mlx_loop_hook(_cub3d->mlx_ptr, ft_draw, _cub3d);
	mlx_hook(_cub3d->mlx_win, 2, 0, key_hook, _cub3d);
	mlx_hook(_cub3d->mlx_win, 17, 0, quit, _cub3d);
	mlx_loop(_cub3d->mlx_ptr);
}
