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
	char	**map;

	(void)ac;
	(void)av;

	if (ac != 2)
		ft_putstr_fd("Error\n\tYou need map file ended with extension \".cub\".\n", 2);
	else
	{
		ft_check_error(av[1]);
		map = ft_read_map(av[1]);
		if (!map)
			return (ft_putstr_fd("Error\n\tGeneral error.\n", 2), 1);
		// <from here i need to free>

		// ft_display(map);
		map = ft_clean_map(map);
		// if (!map)
		// 	return (1);

		// // int error;

		// printf("\t|\n");
		// printf("        |\n");
	}
	
	return (0);
}
