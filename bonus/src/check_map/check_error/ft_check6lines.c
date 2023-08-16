/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check6lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:25:24 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/15 13:55:21 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../../include/cub3d.h"

static int	ft_check_double_coma(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[0] == ',' || line[ft_strlen(line) - 1] == ','
			|| (line[i] == ',' && line[i + 1] == ','))
			return (ft_putstr_fd("Error\n\tin coma.\n", 2), 0);
		i++;
	}
	return (1);
}

static int	ft_check_rgb(char **s, t_cub3d *_cub3d)
{
	char	**rgb;
	int		num;
	int		i;

	i = 0;
	if (!s || !*s || s[2])
		return (ft_putstr_fd("Error\n\tto many args.\n", 2), 0);
	if (!s[1] || !s[1] || !ft_check_double_coma(s[1]))
		return (0);
	rgb = ft_split(s[1], ',');
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255 || i >= 3)
			return (ft_free_map(rgb), ft_putstr_fd("Error\n\tRGB out of range\
.\n", 2), 0);
		i++;
	}
	if (!ft_strncmp(s[0], "F", 2))
		_cub3d->f_rgb = ft_split(s[1], ',');
	else if (!ft_strncmp(s[0], "C", 2))
		_cub3d->c_rgb = ft_split(s[1], ',');
	ft_free_map(rgb);
	return (1);
}

static int	ft_fill_texture_name(char **s, t_cub3d *_cub3d)
{
	if (s[2])
		return (ft_putstr_fd("Error\n\tto many args.\n", 2), 0);
	if (!ft_strncmp(s[0], "NO", 3) && s[1])
		_cub3d->textures[0].name = ft_strdup(s[1]);
	else if (!ft_strncmp(s[0], "SO", 3) && s[1])
		_cub3d->textures[1].name = ft_strdup(s[1]);
	else if (!ft_strncmp(s[0], "EA", 3) && s[1])
		_cub3d->textures[2].name = ft_strdup(s[1]);
	else if (!ft_strncmp(s[0], "WE", 3) && s[1])
		_cub3d->textures[3].name = ft_strdup(s[1]);
	return (1);
}

static int	ft_check_texure(char **s, t_cub3d *_cub3d)
{
	if (!s || !*s)
		return (0);
	if (ft_strncmp(s[0], "NO", 3) && ft_strncmp(s[0], "SO", 3)
		&& ft_strncmp(s[0], "WE", 3) && ft_strncmp(s[0], "EA", 3)
		&& ft_strncmp(s[0], "F", 2) && ft_strncmp(s[0], "C", 2))
		return (ft_putstr_fd("Error\n\tNO | WE | SO | EA | F | C.\n", 2), 0);
	if ((!ft_strncmp(s[0], "NO", 3) || !ft_strncmp(s[0], "SO", 3)
			|| !ft_strncmp(s[0], "WE", 3) || !ft_strncmp(s[0], "EA", 3)))
		if (!ft_fill_texture_name(s, _cub3d))
			return (0);
	if ((!ft_strncmp(s[0], "F", 2) || !ft_strncmp(s[0], "C", 2))
		&& !ft_check_rgb(s, _cub3d))
		return (0);
	return (1);
}

int	ft_check6lines(char **map, t_cub3d *_cub3d)
{
	int		first6line;
	char	**str;

	if (!map || !*map)
		return (ft_putstr_fd("Error\n\tGeneral Error.\n", 2), 0);
	first6line = 0;
	_cub3d->textures[4].name = ft_strdup("./files/texture/door.xpm");
	while (first6line < 6)
	{
		str = ft_split(map[first6line], ' ');
		if (!ft_check_texure(str, _cub3d))
			return (ft_free_map(str), 0);
		ft_free_map(str);
		first6line++;
	}
	return (1);
}
