/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@students.42wolfsbur    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:28:22 by nlalleik          #+#    #+#             */
/*   Updated: 2021/11/28 18:22:29 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a_s1;
	unsigned char	*b_s2;
	size_t			i;

	a_s1 = (unsigned char *)s1;
	b_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (a_s1[i] != b_s2[i])
			return (a_s1[i] - b_s2[i]);
		i++;
	}
	return (0);
}
