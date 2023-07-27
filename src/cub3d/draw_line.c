/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:13:17 by kchaouki          #+#    #+#             */
/*   Updated: 2023/07/27 15:26:00 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void	img_pix_put(t_cub3d *_cub3d, int x, int y, int color)
{
	char    *pixel;

    pixel = _cub3d->img.addr + (y * _cub3d->img.line_len + x * (_cub3d->img.bpp / 8));
	*(int *)pixel = color;
}


static int	take_decision(t_line *line, t_point *p1, t_point *p2)
{
	if (line->e2 >= line->delta_y)
	{
		if (p1->x == p2->x)
			return (1);
		line->error += line->delta_y;
		p1->x += line->incre_x;
	}
	else if (line->e2 <= line->delta_x)
	{
		if (p1->y == p2->y)
			return (1);
		line->error += line->delta_x;
		p1->y += line->incre_y;
	}
	return (0);
}

static void	direction(t_point p1, t_point p2, t_line *line)
{
	if (p1.x < p2.x)
		line->incre_x = 1;
	else
		line->incre_x = -1;
	if (p1.y < p2.y)
		line->incre_y = 1;
	else
		line->incre_y = -1;
}

void	draw_line(t_cub3d *_cub3d ,t_point p2)
{
	t_line	line;
	t_point	p1;

	p1.x = _cub3d->px;
	p1.y = _cub3d->py;
	line.delta_x = abs(p2.x - p1.x);
	line.delta_y = -abs(p2.y - p1.y);
	direction(p1, p2, &line);
	line.error = line.delta_x + line.delta_y;
	while (1)
	{
		if (p1.x >= 0 && p1.x < (_cub3d->width * PIXEL) + 2 && p1.y >= 0 && p1.y < (_cub3d->height * PIXEL) + 2)
			img_pix_put(_cub3d, p1.x, p1.y, 0x00FFFF);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		line.e2 = 2 * line.error;
		if (take_decision(&line, &p1, &p2))
			break ;
	}
}