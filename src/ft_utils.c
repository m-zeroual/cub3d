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

#include "./../include/cub3d.h"

// ft_count_map count lines and return lines
int ft_count_map(char *map_name)
{
	int     fd;
	int     size;
	char    *map;

	fd = open(map_name, 'r');
	if (fd == -1)				// ==> this protection not necessary.
		return (-1);			// because it protect in function ft_check_error.
		
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

char **ft_read_map(char *map_name)
{
	char	**map;
	int		fd;
	int		lines;
	int		count;

	lines = ft_count_map(map_name);
	if (!lines)
		return (0);
	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (0);
	fd = open(map_name, 'r');
	if (fd == -1)       		// ==> this protection not necessary.
		return (0);				// because it protect in function ft_check_error.
	count = 0;
	while (count < lines + 1)
		map[count++] = get_next_line(fd);
	close(fd);
	return (map);
}

char **ft_clean_map(char **map)
{
	char	*line;
	char	**new_map;
	int		i;
	int		i_new_map;

	i_new_map = 0;
	new_map = malloc((ft_count_without_newline(map) + 1) * sizeof(char *));
	if (!new_map)
		return (ft_free_map(map), NULL); // use function ft_free_map to free variable map.
	i = 0;
	while (map[i])
	{
		line = ft_strtrim(map[i],"\n");
		if (*line)
			new_map[i_new_map++] = ft_strdup(line);
		free(line);
		i++;
	}
	ft_free_map(map);
	new_map[i_new_map] = 0;
	return (new_map);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("FREE ==>%s\n", map[i]);
		free(map[i++]);
	}
	free(map);
}
