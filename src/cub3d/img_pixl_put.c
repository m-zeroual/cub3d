/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixl_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:35:53 by mzeroual          #+#    #+#             */
/*   Updated: 2023/07/25 22:54:41 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void	img_pixl_put(t_cub3d *_cub3d, int x, int y, int color)
{
	char    *pixel;

    pixel = _cub3d->img.addr + (y * _cub3d->img.line_len + x * (_cub3d->img.bpp / 8));
	*(int *)pixel = color;
}
