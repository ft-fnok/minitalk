/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:05:01 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/03 15:12:20 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	s2_len = ft_strlen((char *)s2);
	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)&s1[0]);
	while (i < len && s1[i] != '\0')
	{
		if (s1[i] == s2[j] && (i + s2_len) <= len)
		{
			j++;
			while (s1[(i + j)] == s2[j] || s2[j] == '\0')
			{
				if (s2[j] == '\0')
					return ((char *)&s1[i]);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	str1[] = "This is a";
// 	char	str2[] = "s a";
// 	char	*p_str1;
// 	char	*p_str2;
//
// 	char	*p_return;
// 	p_str1 = str1;
// 	p_str2 = str2;
// 	p_return = ft_strnstr(p_str1, p_str2, 9);
// 	printf("%s\n", p_return);
// }