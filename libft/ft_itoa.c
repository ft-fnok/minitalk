/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:52:43 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/02 21:05:32 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	getlen(long nbr, int sign)
{
	size_t	len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	if (sign == (-1))
		len++;
	return (len);
}

static	void	s_populate(char *s, long nbr, size_t len, int sign)
{
	s[len] = '\0';
	if (sign == 1)
	{
		while (len > 0)
		{
			s[(len - 1)] = (nbr % 10) + 48;
			nbr /= 10;
			len--;
		}
	}
	else if (sign == (-1))
	{
		while ((len - 1) > 0)
		{
			s[(len - 1)] = (nbr % 10) + 48;
			nbr /= 10;
			len--;
		}
		s[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nbr;
	size_t	len;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = (-1);
	nbr = (long) n;
	nbr *= sign;
	len = getlen(nbr, sign);
	if (len == 0)
		len = 1;
	s = ft_calloc((len + 1), sizeof(char));
	if (!s)
		return (NULL);
	if (((sign * nbr) > (-2147483649)) && (sign * nbr < 2147483648))
		s_populate(s, nbr, len, sign);
	return (s);
}
