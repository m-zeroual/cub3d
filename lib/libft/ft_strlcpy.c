/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:54:59 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/03 11:10:32 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	i = 0;
	if (n == 0)
		return (lensrc);
	else
	{
		while (i < lensrc && i < n - 1)
		{
			dst[i] = ((char *)src)[i];
			i++;
		}
	}
	dst[i] = 0;
	return (lensrc);
}
