/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:46:14 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/04 23:25:13 by kchaouki         ###   ########.fr       */
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
