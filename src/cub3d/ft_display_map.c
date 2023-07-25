/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:46:14 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/13 08:46:16 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void ft_display_map(char **map)
{
	if (!map)
		return ;
	int i = 6;
	while (map[i])
		printf("%s\n", map[i++]);

}
