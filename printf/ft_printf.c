/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:07:10 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/18 12:19:26 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pf_case_switch(const char *s, va_list ap)
{
	int	out;

	out = 0;
	if (s[0] == 'i' || s[0] == 'd')
		out += ft_pf_case_int(ap);
	else if (s[0] == 's')
		out += ft_pf_case_str(ap);
	else if (s[0] == 'c')
		out += ft_pf_case_char(ap);
	else if (s[0] == 'u')
		out += ft_pf_case_uint(ap);
	else if (s[0] == 'x' || s[0] == 'X')
		out += ft_pf_case_hex(ap, s[0]);
	else if (s[0] == 'p')
		out += ft_pf_case_addr(ap);
	else if (s[0] == '%')
		out += write(1, "%", 1);
	return (out);
}

int	ft_printf(const char *s, ...)
{
	int		out;
	size_t	i;
	va_list	ap;

	out = 0;
	i = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			out += write(1, &s[i], 1);
			i++;
		}
		else
		{
			out += ft_pf_case_switch(&s[i + 1], ap);
			i += 2;
		}
	}
	va_end(ap);
	return (out);
}

// #include <stdio.h>
// int main(void)
// {
// 	// int ret;
// 	int i;
// 	int d;
// 	unsigned int u;
// 	char *s;
// 	char c;
// 	unsigned int h;
//
// 	c = '0';
// 	s = "0";
// 	i = 0;
// 	d = 0;
// 	u = 0;
// 	h = 423524324;
// 	ft_printf("p min = %p\n", -9223372036854775807);
// 	ft_printf("p max = %p\n", 9223372036854775807);
// 	printf("p min = %p\n", -9223372036854775806);
// 	printf("p max = %p\n", 9223372036854775806);
// }