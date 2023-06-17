/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:14:02 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/05 18:30:02 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendst;
	size_t	lensrc;

	if (!size || (!src && !dst))
		return (ft_strlen(src));
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	j = 0;
	if (lendst >= size)
		return (size + lensrc);
	while (dst[j])
		j++;
	while (((char *)src)[i] && j < size - 1)
	{
		dst[j] = ((char *)src)[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (lensrc + lendst);
}
