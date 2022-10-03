/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@students.42wolfsbur    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:00:48 by nlalleik          #+#    #+#             */
/*   Updated: 2021/11/28 18:22:56 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*a_dest;
	char	*b_src;

	a_dest = (char *)dest;
	b_src = (char *)src;
	if (b_src == a_dest)
		return (dest);
	while (n > 0)
	{
		a_dest[n - 1] = b_src[n - 1];
		n--;
	}
	return (dest);
}
