/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:49:38 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/10 17:26:23 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*str;

	if (size >= SIZE_MAX && n >= SIZE_MAX)
		return (0);
	str = malloc(n * size);
	if (!str)
		return (0);
	ft_bzero(str, n * size);
	return (str);
}
