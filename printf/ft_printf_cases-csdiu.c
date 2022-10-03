/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases-csdiu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:27:24 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/18 12:19:43 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pf_case_char(va_list ap)
{
	int	out;
	int	c;

	if (!ap)
		return (0);
	c = va_arg(ap, int);
	out = write(1, &c, 1);
	return (out);
}

int	ft_pf_case_str(va_list ap)
{
	int		out;
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	out = ft_pf_printstr_fd(str, 1);
	return (out);
}

int	ft_pf_case_int(va_list ap)
{
	char	*str;
	int		i;
	int		out;

	i = va_arg(ap, int);
	str = ft_pf_print_ltoa((long) i);
	out = ft_pf_printstr_fd(str, 1);
	free(str);
	return (out);
}

int	ft_pf_case_uint(va_list ap)
{
	char			*str;
	unsigned int	i;
	int				out;

	i = va_arg(ap, unsigned int);
	str = ft_pf_print_ltoa((long) i);
	out = ft_pf_printstr_fd(str, 1);
	free(str);
	return (out);
}
