/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases-xXp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:30:35 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/18 12:19:36 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

int	ft_pf_case_hex(va_list ap, char case_ul)
{
	char			*str;
	unsigned int	i;
	int				out;

	i = va_arg(ap, unsigned int);
	str = ft_pf_hexconvert(i, case_ul);
	out = ft_pf_printstr_fd(str, 1);
	free(str);
	return (out);
}

int	ft_pf_case_addr(va_list ap)
{
	char				*str;
	unsigned long long	i;
	int					out;
	const char			*prefix = "0x";

	i = va_arg(ap, unsigned long long);
	str = ft_pf_hexconvert(i, 'x');
	out = ft_pf_printstr_fd((char *)prefix, 1);
	out += ft_pf_printstr_fd(str, 1);
	free(str);
	return (out);
}
