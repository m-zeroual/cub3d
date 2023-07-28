/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:35:07 by mzeroual          #+#    #+#             */
/*   Updated: 2023/07/28 19:52:56 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_len(const char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[j])
	{
		while (str[j] && str[j] == c)
			j++;
		while (str[j] && str[j] != c)
		{
			if (str[j + 1] == c || !str[j + 1])
				i++;
			j++;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	if (!s || !*s)
		return (NULL);
	i = 0;
	j = check_len(s, c);
	str = ft_calloc(j + 1, sizeof(char *));
	if (!str)
		return (NULL);
	j = 0;
	while (s[j])
	{
		k = 0;
		while (s[j] == c && s[j] != 0)
			j++;
		k = j;
		while (s[j] != c && s[j] != 0)
			j++;
		if (j != k)
			str[i++] = ft_substr(s + k, 0, j - k);
	}
	return (str);
}
