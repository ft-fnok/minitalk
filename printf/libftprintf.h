/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@students.42wolfsbur    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:09:52 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/18 12:24:39 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
/* included for access to va_list va_arg va_start va_end va_copy */
# include "libft.h"
/* included for use of libft functions */

int		ft_printf(const char *s, ...);
int		ft_pf_case_switch(const char *s, va_list ap);
int		ft_pf_case_hex(va_list ap, char case_ul);
int		ft_pf_case_addr(va_list ap);
int		ft_pf_case_char(va_list ap);
int		ft_pf_case_str(va_list ap);
int		ft_pf_case_int(va_list ap);
int		ft_pf_case_uint(va_list ap);
int		ft_pf_printstr_fd(char *s, int fd);
size_t	ft_pf_getlen(unsigned long long nbr, int sign, size_t base);
void	ft_pf_s_populate(char *s, unsigned long long nbr, size_t len, int sign);
char	*ft_pf_print_ltoa(long n);
char	*ft_pf_hexconvert(unsigned long long num, char case_ul);

#endif