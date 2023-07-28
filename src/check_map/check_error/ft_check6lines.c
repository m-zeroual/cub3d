/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check6lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:25:24 by mzeroual          #+#    #+#             */
/*   Updated: 2023/07/28 23:08:09 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"

static int	check_file_exist(char *file_name)
{
	int	fd;

	if (!file_name)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
}

static int	ft_check4lines(char *line, int pos)
{
	char	**file_texture;

	if (!line)
		return (0);
	file_texture = ft_split(line, ' ');
	if ((pos != 0 || ft_strncmp(*file_texture, "NO", 3))
		&& (pos != 1 || ft_strncmp(*file_texture, "SO", 3))
		&& (pos != 2 || ft_strncmp(*file_texture, "WE", 3))
		&& (pos != 3 || ft_strncmp(*file_texture, "EA", 3)))
		return (0);
	if (!check_file_exist(file_texture[1]))
		return (0);
	ft_free_map(file_texture);
	return (1);
}

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
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check4_5lines(char *line, int pos)
{
	int		i;
	int		num;
	char	**str;
	char	**number;

	if (!line)
		return (0);
	number = 0;
	str = ft_split(line, ' ');
	if ((pos != 4 || ft_strncmp(*str, "F", 2))
		&& (pos != 5 || ft_strncmp(*str, "C", 2)))
		return (0);
	number = ft_split(str[1], ',');
	if (!number || !ft_check_double_coma(str[1]) || str[2])
		return (0);
	i = 0;
	while (number[i])
	{
		num = ft_atoi(number[i++]);
		if (num < 0 || num > 255 || i > 3)
			return (0);
	}
	return (ft_free_map(str), ft_free_map(number), 1);
}

int	ft_check6lines(char **map)
{
	int	first6line;

	if (!map || !*map)
		return (0);
	first6line = 0;
	while (first6line < 6)
	{
		if (first6line < 4)
			if (!ft_check4lines(map[first6line], first6line))
				return (0);
		if (first6line >= 4 && first6line < 6)
			if (!ft_check4_5lines(map[first6line], first6line))
				return (0);
		first6line++;
	}
	return (1);
}
