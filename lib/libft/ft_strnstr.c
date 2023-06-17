/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:38:06 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/11 16:14:24 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!dst && len == 0)
		return (0);
	if (*src == 0)
		return ((char *)dst);
	while (dst[i] && i < len)
	{
		j = 0;
		while (dst[i + j] == src[j] && (i + j) < len)
		{
			if (src[j + 1] == '\0')
				return (&((char *)dst)[i]);
			j++;
		}
		i++;
	}
	return (0);
}
