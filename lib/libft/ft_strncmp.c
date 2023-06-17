/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:40:09 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/10 17:17:50 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s1;
	i = 0;
	while ((str[i] || s2[i]) && i < n)
	{
		if (str[i] < s2[i])
			return (-1);
		if (str[i] > s2[i])
			return (1);
		if (str[i] == s2[i])
			i++;
	}
	return (0);
}
