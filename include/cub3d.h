/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:40 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/13 08:44:43 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	CUB3D_FT
# define CUB3D_FT

#include "./../lib/libft/libft.h"
#include "./../lib/get_next_line/get_next_line.h"
#include <stdio.h>


//====> ft_display_map.c <=====
void ft_display(char **map);

//====> ft_error.c <=====
void ft_check_error(char *map_name);

//====> ft_utils.c <=====
int ft_count_map(char *map_name);
char **ft_read_map(char *map_name);
int	ft_count_without_newline(char **map);
char **ft_clean_map(char **map);
void	ft_free_map(char **map);

#endif
