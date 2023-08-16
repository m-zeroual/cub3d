/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:28:31 by mzeroual          #+#    #+#             */
/*   Updated: 2023/08/15 13:50:41 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../../include/cub3d.h"

static int	ft_check_extension(char *map_name)
{
	if (ft_strncmp((map_name + (ft_strlen(map_name) - 4)), ".cub", 4))
		return (0);
	else
		return (1);
}

void	ft_check_error(char *map_name)
{
	int	fd;

	if (!ft_check_extension(map_name))
	{
		ft_putstr_fd("Error\n\tExtension is not \'.cub\'.\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n\tFail to open File.\n", 2);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
