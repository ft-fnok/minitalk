/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:14:57 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/15 23:48:19 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (!size)
		return (ft_strlen(src));
	while ((len < (size - 1)) && (src[len] != '\0'))
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	while (src[len] != 0)
		len++;
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	destination[14] = "";
// 	char	source[] = "A";
//
// 	ft_strlcpy(destination, source, sizeof(source)-1);
// 	printf("size_of(dest) = %lu\n%s\n", sizeof(source), destination);
// 	return (0);
// }