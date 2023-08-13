/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:46:14 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/10 17:24:06 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void	ft_display_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		printf("%s\n", map[i++]);
}
