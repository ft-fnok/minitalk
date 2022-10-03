/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:12:45 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/09 15:26:41 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*s;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_strrchr(set, s1[i]) != NULL)
		i++;
	if (i == len)
		return (ft_strdup(""));
	while (i <= len && ft_strrchr(set, s1[len - 1]) != NULL)
			len--;
	s = ft_calloc((len - i + 1), sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, &s1[i], len - i + 1);
	return (s);
}
