/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check6lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:25:24 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/15 17:25:26 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"

int ft_check4lines(char *line, int pos, char **map)
{
    if ((pos != 0 || ft_strncmp(line, "NO", 2)) && (pos != 1 || ft_strncmp(line, "SO", 2)) &&
		(pos != 2 || ft_strncmp(line, "WE", 2)) && (pos != 3 || ft_strncmp(line, "EA", 2)))
	{
		ft_putstr_fd("Error\n\tCardinal directions.\n",2);
		ft_free_map(map);
		return (0);
	}
	return (1);
}

int ft_check4_5lines(char *line, int pos, char **map)
{
	int		i;
	int		num;
	char	**str;
	char	**number;

	number = 0;
    if ((pos != 4 || ft_strncmp(line, "F", 1)) && (pos != 5 || ft_strncmp(line, "C", 1)))
		return (ft_putstr_fd("Error\n\tF and C error.\n",2), ft_free_map(map), 0);
	else
	{
		str = ft_split(line, ' ');
		number = ft_split(str[1], ',');
		ft_free_map(str);
		i = 0;
		while (number[i])
		{
			num = ft_atoi(number[i++]);
			if (num < 0 || num > 255)
				return (ft_putstr_fd("Error\n\tNumber out of Range in RGB.\n",2), ft_free_map(map), 0);
		}
		ft_free_map(number);
	}
	return (1);
}

void ft_check6lines(char **map)
{
	int i;
	int first6line;

	first6line = 0;
	while (first6line < 6)
	{
		i = 0;
		while (map[first6line][i] && (map[first6line][i] == ' ' || map[first6line][i] == '\t'))
			i++;
		if (map[first6line][i] == '\0')
			first6line++;
        if (first6line < 4)
		    if (!ft_check4lines(&map[first6line][i], first6line, map))
				exit(1);
		if (first6line >= 4 && first6line < 6)
		    if (!ft_check4_5lines(&map[first6line][i], first6line, map))
				exit(1);
		first6line++;
	}
	
}
