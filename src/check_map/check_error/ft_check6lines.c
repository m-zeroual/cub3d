/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check6lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:25:24 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/05 20:28:34 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"


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

static int ft_check_rgb(char *s, char *line, t_cub3d *_cub3d)
{
	char **rgb;
	int num;
	int i = 0;

	if (!line || !*line || !ft_check_double_coma(line))
		return (0);
	rgb = ft_split(line, ',');
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255 || i >= 3)
			return (ft_free_map(rgb), ft_putstr_fd("Error\n\tRGB out of range.\n", 2), 0);
		i++;
	}
	if (!ft_strncmp(s, "F", 1))
		_cub3d->f_rgb = ft_split(line, ',');
	else if (!ft_strncmp(s, "C", 1))
		_cub3d->c_rgb = ft_split(line, ',');
	ft_free_map(rgb);
	return (1);
}

static int ft_fill_texture_name(char **s, t_cub3d *_cub3d)
{
	if (s[2])
		return (ft_putstr_fd("Error\n\tGeneral Error.\n", 2), 0);
	if (!ft_strncmp(s[0], "NO", 2) && s[1])
		_cub3d->north.name = ft_strdup(s[1]);
	else if (!ft_strncmp(s[0], "WE", 2) && s[1])
		_cub3d->west.name = ft_strdup(s[1]);
	else if (!ft_strncmp(s[0], "SO", 2) && s[1])
		_cub3d->south.name = ft_strdup(s[1]);
	else if (!ft_strncmp(s[0], "EA", 2) && s[1])
		_cub3d->east.name = ft_strdup(s[1]);
	return (1);
}
static int	ft_check_texure(char **s, t_cub3d *_cub3d)
{
	if (!s || !*s)
		return (0);
	if (ft_strncmp(s[0], "NO", 2) && ft_strncmp(s[0], "SO", 2)
	&& ft_strncmp(s[0], "WE", 2) && ft_strncmp(s[0], "EA", 2)
	&& ft_strncmp(s[0], "F", 1) && ft_strncmp(s[0], "C", 1))
		return (ft_putstr_fd("Error\n\tNO | WE | SO | EA | F | C.\n", 2), 0);
	if ((!ft_strncmp(s[0], "NO", 2) || !ft_strncmp(s[0], "SO", 2)
	|| !ft_strncmp(s[0], "WE", 2) || !ft_strncmp(s[0], "EA", 2)))
		if (!ft_fill_texture_name(s, _cub3d))
			return (0);
	if ((!ft_strncmp(s[0], "F", 1) || !ft_strncmp(s[0], "C", 1))
	&& !ft_check_rgb(s[0], s[1], _cub3d))
		return (0);
	return (1);
}

int	ft_check6lines(char **map, t_cub3d *_cub3d)
{
	int		first6line;
	char	**str;

	if (!map || !*map)
		return (0);
	first6line = 0;
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
