/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:01:38 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/05 18:33:44 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned int	i;
	unsigned int	n;

	i = 1;
	n = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			i *= -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		n = (10 * n) + (*s - 48);
		s++;
	}
	if (*s && !ft_isdigit(*s))
		return (-1);
	return (n * i);
}
