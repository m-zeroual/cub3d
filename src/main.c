/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:18:38 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/12 20:19:15 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"


int main(int ac, char *av[])
{
	t_cub3d _cub3d;
	if (ac == 2)
	{
		if (!parse_map(av[1], &_cub3d))
			return (0);
			
		_cub3d.map = ft_read_map(av[1]) + _cub3d.index_map;
		// printf("start = %d\n", _cub3d.index_map);
		
		if (!_cub3d.map)
			return (1);
		printf("start = %s", _cub3d.map[0]);
		cub3d(&_cub3d);
	}
	else
		ft_putstr_fd("Error\n\tYou need map file ended with extension \".cub\".\n", 2);
	return (0);
}
