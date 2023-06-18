/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:18:38 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/13 09:18:41 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"


int main(int ac, char *av[])
{
	t_cub3d _cub3d;
	if (ac == 2)
	{
		_cub3d.map = parse_map(av[1]);
		if (!_cub3d.map)
			return (1);
		cub3d(&_cub3d);
	}
	else
		ft_putstr_fd("Error\n\tYou need map file ended with extension \".cub\".\n", 2);
	return (0);
}
