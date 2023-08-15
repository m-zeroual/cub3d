/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:46:14 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/15 13:57:44 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/cub3d.h"

void	ft_display_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		printf("%s\n", map[i++]);
}
