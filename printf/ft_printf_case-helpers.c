/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_case-helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:42:53 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/18 12:19:52 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pf_printstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = 0;
	if (s)
		s_len = ft_strlen(s);
	while (i < s_len)
	{
		write(fd, &s[i], 1);
		i++;
	}
	return ((int)s_len);
}

size_t	ft_pf_getlen(unsigned long long nbr, int sign, size_t base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	if (sign == (-1))
		len++;
	return (len);
}

void	ft_pf_s_populate(char *s, unsigned long long nbr, size_t len, int sign)
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

char	*ft_pf_print_ltoa(long n)
{
	char	*s;
	long	nbr;
	size_t	len;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = (-1);
	nbr = n;
	nbr *= sign;
	len = ft_pf_getlen(nbr, sign, 10);
	if (len == 0)
		len = 1;
	s = ft_calloc((len + 1), sizeof(char));
	if (!s)
		return (NULL);
	ft_pf_s_populate(s, nbr, len, sign);
	return (s);
}

char	*ft_pf_hexconvert(unsigned long long num, char case_ul)
{
	char			*hex;
	unsigned int	buf;
	size_t			i;

	i = ft_pf_getlen(num, 1, 16);
	hex = (char *)malloc((i + 1) * sizeof(char));
	hex[i] = '\0';
	i--;
	if (num == 0)
		hex[i] = '0';
	while (num > 0)
	{
		buf = (num % 16);
		if (buf <= 9)
			hex[i] = buf + 48;
		else if (case_ul == 'X')
			hex[i] = buf + 55;
		else
			hex[i] = buf + 87;
		i--;
		num /= 16;
	}
	return (hex);
}
