/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:58:47 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/15 15:08:33 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"

int	img_get_pixel_color(t_texture texture, int x, int y)
{
	char	*pixel;

	pixel = texture.img.addr + \
	(y * texture.img.line_len + x * (texture.img.bpp / 8));
	return (*(int *)pixel);
}

void	open_textures(t_cub3d *_cub3d)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_cub3d->textures[i].img.mlx_img = \
		mlx_xpm_file_to_image(_cub3d->mlx_ptr, _cub3d->textures[i].name, \
		&_cub3d->textures[i].width, &_cub3d->textures[i].height);
		if (!_cub3d->textures[i].img.mlx_img)
		{
			ft_putstr_fd("Error in texture\n", 2);
			exit(1);
		}
		_cub3d->textures[i].img.addr = \
		mlx_get_data_addr(_cub3d->textures[i].img.mlx_img, \
		&_cub3d->textures[i].img.bpp, &_cub3d->textures[i].img.line_len, \
		&_cub3d->textures[i].img.endian);
		i++;
	}
}

int	get_color(t_cub3d *_cub3d, int ceile_or_floor)
{
	int	r;
	int	g;
	int	b;

	if (ceile_or_floor == 1)
	{
		r = ft_atoi(_cub3d->c_rgb[0]);
		g = ft_atoi(_cub3d->c_rgb[1]);
		b = ft_atoi(_cub3d->c_rgb[2]);
	}
	else
	{
		r = ft_atoi(_cub3d->f_rgb[0]);
		g = ft_atoi(_cub3d->f_rgb[1]);
		b = ft_atoi(_cub3d->f_rgb[2]);
	}
	return (r << 16 | g << 8 | b);
}

int	is_upside_wall(t_cub3d *_cub3d, int x, int y)
{
	if (_cub3d->map[(int)((y + PLAYER_SIZE / 2) / PIXEL)] \
	[(int)(x / PIXEL)] == '1')
		return (1);
	else if (_cub3d->map[(int)((y - PLAYER_SIZE / 2) / PIXEL)] \
	[(int)(x / PIXEL)] == '1')
		return (1);
	else if (_cub3d->map[(int)(y / PIXEL)] \
	[(int)((x - PLAYER_SIZE / 2) / PIXEL)] == '1')
		return (1);
	else if (_cub3d->map[(int)(y / PIXEL)] \
	[(int)((x + PLAYER_SIZE / 2) / PIXEL)] == '1')
		return (1);
	return (0);
}

int	quit(t_cub3d *_cub3d)
{
	int	i;

	i = 0;
	while (i < 4)
		mlx_destroy_image(_cub3d->mlx_ptr, _cub3d->textures[i++].img.mlx_img);
	mlx_destroy_window(_cub3d->mlx_ptr, _cub3d->mlx_win);
	ft_free_all(_cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}
