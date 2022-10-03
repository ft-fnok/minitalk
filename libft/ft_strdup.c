/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@students.42wolfsbur    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:15:20 by nlalleik          #+#    #+#             */
/*   Updated: 2021/11/29 21:41:48 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	dup = ft_calloc((len + 1), sizeof(char));
	if (dup == NULL)
		return (0);
	while (len > 0)
	{
		dup[len - 1] = s[len - 1];
		len--;
	}
	return (dup);
}
