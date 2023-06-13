/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:40 by mzeroual          #+#    #+#             */
/*   Updated: 2023/06/13 08:44:43 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	FT_CUB3D_FT
# define FT_CUB3D_FT

#include "./../lib/libft/libft.h"
#include "./../lib/get_next_line/get_next_line.h"
#include <stdio.h>


//====> ft_display_map.c <=====
void ft_display(char **map);

//====> ft_utils.c <=====
int ft_count_map();
char **ft_read_map();
int	ft_count_without_newline(char **map);
char **ft_remove(char **map);

#endif
