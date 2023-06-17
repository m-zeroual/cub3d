/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:34:37 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/06 17:42:53 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_int(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char		*memmory;
	int			len;
	int			j;
	long int	n;

	n = nb;
	j = 0;
	len = len_int(n);
	memmory = malloc(len + 1);
	if (!memmory)
		return (0);
	if (n < 0)
	{
		memmory[0] = '-';
		n *= -1;
	}
	memmory[len] = 0;
	if (n == 0)
		memmory[0] = '0';
	while (n)
	{
		memmory[--len] = 48 + n % 10;
		n /= 10;
	}
	return (memmory);
}
