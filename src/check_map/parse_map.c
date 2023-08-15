/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:51:54 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/15 12:45:04 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

int check_door(int i, int j, char **new_map)
{
	if ((new_map[i - 1][j] == '1' && new_map[i + 1][j] == '1')
		|| (new_map[i][j - 1] == '1' && new_map[i][j + 1] == '1'))
		return (1);
	return (0);
}

int	condition(int i, int j, int *player, char **new_map)
{
	if (new_map[i][j] == 'N' || new_map[i][j] == 'W' || new_map[i][j] == 'E'
	|| new_map[i][j] == 'S' || new_map[i][j] == ' ' || new_map[i][j] == '0'
	|| new_map[i][j] == '1' || new_map[i][j] == 'D')
	{
		if (new_map[i][j] == '0' || new_map[i][j] == 'N'
		|| new_map[i][j] == 'W' || new_map[i][j] == 'E'
		|| new_map[i][j] == 'S' || new_map[i][j] == 'D')
		{
			if (i == 6 || i == ft_count_without_newline(new_map) - 1 || j == 0
				|| j == (int)ft_strlen(new_map[i]) - 1
				|| new_map[i - 1][j] == ' ' || new_map[i][j + 1] == ' '
				|| new_map[i + 1][j] == ' ' || new_map[i][j - 1] == ' '
				|| j >= (int)ft_strlen(new_map[i - 1])
				|| j >= (int)ft_strlen(new_map[i + 1]))
				return (ft_putstr_fd("Error\n\tmap error.\n", 2), 0);
			if (new_map[i][j] == 'D' && !check_door(i, j, new_map))
				return (ft_putstr_fd("Error\n\terror in door.\n", 2),0);
			if (new_map[i][j] == 'N' || new_map[i][j] == 'W'
			|| new_map[i][j] == 'E' || new_map[i][j] == 'S')
				(*player)++;
		}
	}
	else
		return (ft_putstr_fd("Error\n\t\
 You have caractere in map not allowed.\n", 2), 0);
	return (1);
}

static int	check_map(char **new_map)
{
	int	line;
	int	colum;
	int	player;

	line = 5;
	player = 0;
	while (new_map[++line])
	{
		colum = 0;
		while (new_map[line][colum])
		{
			if (!condition(line, colum, &player, new_map))
				return (0);
			colum++;
		}
	}
	if (player != 1)
		return (ft_putstr_fd("Error\n\terror in player.\n", 2), 0);
	return (1);
}

int	parse_map(char *map_name, t_cub3d *_cub3d)
{
	char	**map;
	char	**new_map;

	ft_check_error(map_name);
	map = ft_read_map(map_name);
	if (!map)
		return (ft_putstr_fd("Error\n\tGeneral error.\n", 2), 0);
	new_map = ft_clean_map(map, _cub3d);
	if (!new_map || !*new_map)
		return (0);
	ft_free_map(map);
	if (!check_map(new_map))
		return (ft_free_map(new_map), 0);
	ft_free_map(new_map);
	return (1);
}
