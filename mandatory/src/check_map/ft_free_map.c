/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:57:18 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/15 14:47:43 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	ft_free_all(t_cub3d *_cub3d)
{
	int	i;

	i = 0;
	ft_free_map(_cub3d->map - _cub3d->index_map);
	ft_free_map(_cub3d->c_rgb);
	ft_free_map(_cub3d->f_rgb);
	while (i < 4)
		free(_cub3d->textures[i++].name);
}
