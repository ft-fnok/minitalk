/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@students.42wolfsbur    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:45:41 by nlalleike         #+#    #+#             */
/*   Updated: 2021/12/17 12:10:15 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = ft_calloc(1, sizeof(char));
		if (substr == NULL)
			return (NULL);
	}
	else
	{
		if (start + len > s_len)
			len = s_len - start;
		substr = ft_calloc(len + 1, sizeof(char));
		if (substr == NULL)
			return (NULL);
		ft_strlcpy(substr, s + start, len + 1);
	}
	return (substr);
}
