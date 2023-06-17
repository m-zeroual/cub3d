/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:35:07 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/11 18:43:53 by mzeroual         ###   ########.fr       */
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

	if (!s)
		return (0);
	i = 0;
	j = check_len(s, c);
	str = ft_calloc(j + 1, sizeof(char *));
	if (!str)
		return (0);
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
