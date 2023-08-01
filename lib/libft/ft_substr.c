/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:35:15 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/05 14:42:23 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*b;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	b = malloc(sizeof(char) * (len + 1));
	if (!b)
		return (0);
	while (i < len && start < ft_strlen(s))
	{
		b[i] = s[start + i];
		i++;
	}
	b[i] = '\0';
	return (b);
}
