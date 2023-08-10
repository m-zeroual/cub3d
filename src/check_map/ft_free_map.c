/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:57:18 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/10 17:21:09 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

void	ft_free_all(t_cub3d *_cub3d)
{
	int	i;

	i = 0;
	ft_free_map(_cub3d->map);
	ft_free_map(_cub3d->c_rgb);
	ft_free_map(_cub3d->f_rgb);
	while (i < 5)
		free(_cub3d->textures[i++].name);
}
