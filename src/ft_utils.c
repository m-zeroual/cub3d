/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:20:00 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/13 09:20:03 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_cub3d.h"

// ft_count_map return -1 in error otherwise return lines
int ft_count_map()
{
	int     fd;
	int     size;
	char    *map;

	fd = open("map/map.cub", 'r');
	if (fd == -1)
		return (-1);
	map = get_next_line(fd);
	size = 0;
	while (map)
	{
		size++;
		map = get_next_line(fd);
	}
	close(fd);
	return (size);

}

char **ft_read_map()
{
	char	**map;
	int		fd;
	int		lines;
	int		count;

	lines = ft_count_map();
	if (lines == -1)
		return (0);
	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (0);
	fd = open("map/map.cub", 'r');
	if (fd == -1)
		return (0);

	count = 0;
	while (count < lines + 1)
		map[count++] = get_next_line(fd);
	close(fd);
	return (map);

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
		line = ft_strtrim(map[i]," \t\n");
		if (*line)
			count++;
		i++;
	}
	return (count);
}

char **ft_remove(char **map)
{
	char	*line;
	char	**new_map;
	int		i;
	int		i_new_map;

	i_new_map = 0;
	new_map = malloc((ft_count_without_newline(map) + 1) * sizeof(char *));
	if (!new_map)
		return (0);
	i = 0;
	while (map[i])
	{
		line = ft_strtrim(map[i]," \t\n");
		free(map[i]);
		if (*line)
			new_map[i_new_map++] = ft_strdup(line);
		free(line);
		i++;
	}
	new_map[i_new_map] = 0;
	return (new_map);
}
