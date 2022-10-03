/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:31:22 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/16 00:02:47 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a_dest;
	size_t			i;

	a_dest = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (a_dest[i] == (unsigned char) c)
			return ((void *)&a_dest[i]);
		i++;
	}
	return (NULL);
}
