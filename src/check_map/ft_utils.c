/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:20:00 by mzeroual          #+#    #+#             */
/*   Updated: 2023/07/28 23:09:27 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

static int	all_line_speace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' || line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_without_newline(char **map)
{
	char	*line;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (map[i])
	{
		line = ft_strtrim(map[i], "\n");
		if (*line)
			count++;
		free(line);
		i++;
	}
	return (count);
}

int	ft_count_map(char *map_name)
{
	int		fd;
	int		size;
	char	*map;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	map = get_next_line(fd);
	size = 0;
	while (map)
	{
		free(map);
		size++;
		map = get_next_line(fd);
	}
	close(fd);
	return (size);
}

char	**ft_read_map(char *map_name)
{
	char	**map;
	int		fd;
	int		lines;
	int		count;

	lines = ft_count_map(map_name);
	if (!lines)
		return (NULL);
	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	count = 0;
	while (count < lines + 1)
		map[count++] = get_next_line(fd);
	close(fd);
	return (map);
}

char	**ft_clean_map(char **map)
{
	char	*line;
	char	**new_map;
	int		i;
	int		i_new_map;

	i_new_map = 0;
	new_map = malloc((ft_count_without_newline(map) + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		line = ft_strtrim(map[i], "\n");
		if (*line && all_line_speace(line))
			new_map[i_new_map++] = ft_strdup(line);
		free(line);
		i++;
	}
	new_map[i_new_map] = 0;
	if (!ft_check6lines(new_map))
		return (ft_free_map(map), NULL);
	return (new_map);
}
