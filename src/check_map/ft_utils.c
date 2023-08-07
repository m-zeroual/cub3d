/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:20:00 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/06 21:52:21 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

// static int	all_line_speace(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] != ' ' && line[i] != '\t')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

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

char	**ft_clean_map(char **map, t_cub3d *_cub3d)
{
	char	*line;
	char	**new_map;
	int		count[3];

	count[0] = -1;
	count[1] = 0;
	count[2] = 0;
	new_map = malloc((ft_count_without_newline(map) + 1) * sizeof(char *));
	if (!new_map)
		return (ft_free_map(map) , NULL);
	while (map[++count[0]])
	{
		line = ft_strtrim(map[count[0]], " \t\n");
		if (*line)
		{
			if(count[2] == 1)
				return (ft_putstr_fd("Error\n\tnew line in the map.\n", 2), ft_free_map(map), NULL);
			new_map[count[1]++] = ft_strdup(line);
		}
		if (count[1] >= 7 && *line == 0)
			count[2] = 1;
		free(line);
	}
	new_map[count[1]] = 0;
	if (!ft_check6lines(new_map, _cub3d))
		return (ft_free_map(new_map), ft_free_map(map), NULL);
	return (new_map);
}
