/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:17:32 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/10 16:54:32 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	j;

	if (!s1 || !set)
		return (0);
	while (*s1 && (ft_strchr(set, *s1)))
		s1++;
	j = ft_strlen(s1) - 1;
	while (*s1 && ft_strrchr(set, s1[j]))
		j--;
	return (ft_substr(s1, 0, j + 1));
}
