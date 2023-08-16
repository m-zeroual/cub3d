/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:44:02 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/31 16:46:55 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	p = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i++] = s2[j];
		j++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if ((char )c == *(char *)str)
			return ((char *)str);
		str++;
		i++;
	}
	return (0);
}

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
