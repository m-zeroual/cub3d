/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check6lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:25:24 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/05 13:06:56 by mzeroual         ###   ########.fr       */
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

static int ft_check_rgb(char *line)
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
	ft_free_map(rgb);
	return (1);
}


static int	ft_check_texure(char **s)
{
	int	i;
	int	fd;

	i = -1;
	if (!s || !*s)
		return (0);
	while (s[++i])
	{
		if (i == 0 && ft_strncmp(s[i], "NO", 2) && ft_strncmp(s[i], "SO", 2)
		&& ft_strncmp(s[i], "WE", 2) && ft_strncmp(s[i], "EA", 2)
		&& ft_strncmp(s[i], "F", 1) && ft_strncmp(s[i], "C", 1))
			return (ft_putstr_fd("Error\n\tNO | WE | SO | EA | F | C.\n", 2), 0);
		if (i == 1 && (!ft_strncmp(s[0], "NO", 2) || !ft_strncmp(s[0], "SO", 2)
		|| !ft_strncmp(s[0], "WE", 2) || !ft_strncmp(s[0], "EA", 2)))
		{
			fd = open(s[i], O_RDONLY);
			if (fd == -1)
				return (ft_putstr_fd("Error\nimage not found.\n", 2), 0);
		}
		if (i == 1 && (!ft_strncmp(s[0], "F", 1) || !ft_strncmp(s[0], "C", 1)) && !ft_check_rgb(s[1]))
			return (0);
		if (i > 1)
			return (ft_putstr_fd("Error\n\tGeneral Error.\n", 2), 0);
	}
	return (1);
}

int	ft_check6lines(char **map)
{
	int		first6line;
	char	**str;

	if (!map || !*map)
		return (0);
	first6line = 0;
	while (first6line < 6)
	{
		str = ft_split(map[first6line], ' ');
		if (!ft_check_texure(str))
			return (ft_free_map(str), 0);
		ft_free_map(str);
		first6line++;
	}
	return (1);
}
