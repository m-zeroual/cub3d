/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:51:54 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/15 18:51:57 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

int	condition(int i, int j, int *player, char **new_map)
{
	if (new_map[i][j] == 'N' || new_map[i][j] == 'W' || new_map[i][j] == 'E'
	|| new_map[i][j] == 'S' || new_map[i][j] == ' ' || new_map[i][j] == '0'
	|| new_map[i][j] == '1' || new_map[i][j] == '\n')
	{
		if (new_map[i][j] == '0')
		{
			if (i == 6 || i == ft_count_without_newline(new_map) - 1 || j == 0
				|| j == (int)ft_strlen(new_map[i]) - 1
				|| new_map[i - 1][j] == ' ' || new_map[i][j + 1] == ' '
				|| new_map[i + 1][j] == ' ' || new_map[i][j - 1] == ' '
				|| j >= (int)ft_strlen(new_map[i - 1])
				|| j >= (int)ft_strlen(new_map[i + 1]))
				return (ft_putstr_fd("Error\n\tmap error.\n", 2), 0);
		}
		else if (new_map[i][j] == 'N' || new_map[i][j] == 'W'
		|| new_map[i][j] == 'E' || new_map[i][j] == 'S')
		(*player)++;
	}
	else
		return (ft_putstr_fd("Error\n\t\
 You have caractere in map not allowed.\n", 2), 0);
	return (1);
}

int ft_check_line(char *line)
{
	int i = 0;
	while (line[i] && (line[i] == '\t' || line[i] == ' ' || line[i] == '\n'))
		i++;
	if (!line[i] || ft_isalpha(line[i]))
		return (1);
	return (0);
}

int	check_map(char **new_map, char **last_map)
{
	int i;
	int	line;
	int	colum;
	int	player;

	line = 6;
	player = 0;
	i = 0;
	while (new_map[line])
	{
		while (line == 6 && ft_check_line(last_map[i]))
			i++;
		if (ft_strncmp(new_map[line], last_map[i], ft_strlen(new_map[line])))
			return (ft_putstr_fd("Error\n\tmap error.\n", 2), 0);
		colum = 0;
		while (new_map[line][colum])
		{
			if (!condition(line, colum, &player, new_map))
				return (ft_free_map(new_map), 0);
			colum++;
		}
		line++;
		i++;
	}
	if (player != 1)
		return (ft_putstr_fd("Error\n\tPlayer not exist\
 or you have double player.\n", 2), ft_free_map(new_map), 0);
	return (1);
}

char	**parse_map(char *map_name)
{
	char	**map;
	char	**new_map;

	ft_check_error(map_name);
	map = ft_read_map(map_name);
	if (!map)
		return (ft_putstr_fd("Error\n\tGeneral error.\n", 2), NULL);
	new_map = ft_clean_map(map);
	if (!new_map)
		return (NULL);
	if (!check_map(new_map, map))
		exit(EXIT_FAILURE);
	return (new_map);
}
