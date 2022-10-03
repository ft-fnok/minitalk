/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@students.42wolfsbur    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:33:13 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/01 22:21:31 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
}
