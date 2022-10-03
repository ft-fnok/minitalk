/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@students.42wolfsbur    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:49:34 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/01 22:20:55 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	translate(int n, size_t len, int fd)
{
	char	s[12];
	long	nbr;
	int		sign;
	size_t	i;

	nbr = (long) n;
	sign = 1;
	i = 0;
	if (nbr < 0)
	{
		sign = (-1);
		s[i] = '-';
		i++;
	}
	i += len;
	s[i--] = '\0';
	nbr *= sign;
	while (len > 0)
	{
		s[i] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
		i--;
	}
	ft_putstr_fd(s, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	long	nbr;

	len = 0;
	nbr = (long) n;
	if ((nbr > -2147483649) && (nbr < 2147483648) && (nbr != 0))
	{
		if (nbr < 0)
			nbr *= (-1);
		while (nbr > 0)
		{
			nbr /= 10;
			len++;
		}
		translate(n, len, fd);
	}
	else if (nbr == 0)
		ft_putchar_fd('0', fd);
}
