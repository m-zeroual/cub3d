/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:51:54 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/15 18:51:57 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

// void check_map()
// {
    
// }

int parse_map(char *map_name)
{
	char	**new_map;

    // first parse
    // --------------------------------------
	ft_check_error(map_name);       // ===> Extension and File exist
	new_map = ft_read_map(map_name);
	if (!new_map)
		return (ft_putstr_fd("Error\n\tGeneral error.\n", 2), 0);
	
	// <from here i need to free>
	new_map = ft_clean_map(new_map);
	if (!new_map)
		return (0);
	// here evreything clean.
	ft_display(new_map);

	ft_check6lines(new_map);
    // --------------------------------------

    // second parse
    // ======================================
	// check_map();
    // ======================================

	ft_display(new_map);
	return (1);
}
