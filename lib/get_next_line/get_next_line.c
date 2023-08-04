/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:18:53 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/26 14:16:12 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdio.h>
#include <fcntl.h>

char	*ft_get_big_line(int fd, char *stock)
{
	char	*buffer;
	char	*str;
	int		count;

	count = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	while (count)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buffer[count] = 0;
		str = stock;
		stock = ft_strjoin(str, buffer);
		free(str);
		if (ft_strchr(stock, '\n'))
			break ;
	}
	free(buffer);
	return (stock);
}

char	*ft_get_line(char *str, char **stock)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	line = ft_substr(str, 0, i + 1);
	*stock = ft_substr(str + i, 1, ft_strlen(str) - i);
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;
	char		*big_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!stock)
		stock = ft_strdup(""); 
	big_line = ft_get_big_line(fd, stock);
	stock = 0;
	if (*big_line == 0)
	{
		free(big_line);
		return (0);
	}
	line = ft_get_line(big_line, &stock);
	return (line);
}