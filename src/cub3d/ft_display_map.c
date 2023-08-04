/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:46:14 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/04 16:08:39 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void ft_display_map(char **map)
{
	if (!map)
		return ;
	int i = 0;
	while (map[i])
		printf("%s\n", map[i++]);

}
