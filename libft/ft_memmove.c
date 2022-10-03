/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:09:52 by nlalleik          #+#    #+#             */
/*   Updated: 2021/11/29 17:34:55 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a_dest;
	unsigned char	*b_src;
	size_t			i;

	a_dest = (unsigned char *) dest;
	b_src = (unsigned char *) src;
	i = 0;
	if (dest == src)
		return ((void *)dest);
	else if (a_dest < b_src)
	{
		while (i++ < n)
			a_dest[i - 1] = b_src[i - 1];
	}
	else if (b_src < a_dest)
	{
		while (n > 0)
		{
			a_dest[n - 1] = b_src[n - 1];
			n--;
		}
	}
	return ((void *)dest);
}
