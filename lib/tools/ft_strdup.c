/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:19:05 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/03 18:48:37 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(ft_strlen(s1) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
