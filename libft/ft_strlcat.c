/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:39:49 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/19 11:42:53 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	len_dest = ft_strlen(dest);
	const size_t	len_src = ft_strlen((char *)src);
	size_t			i;

	i = 0;
	if (size > len_dest && (int *)len_src != NULL)
	{
		while (src[i] != '\0' && len_dest + i <= size)
		{
			dest[len_dest + i] = src[i];
			dest[len_dest + (i + 1)] = '\0';
			i++;
		}
	}
	if (size <= len_dest)
		return (size + len_src);
	dest[(size - 1)] = '\0';
	return (len_dest + len_src);
}

// #include <stdio.h>
//  int main(void)
//  {
//     char dest[20] = "";
//     int i =    ft_strlcat(dest, "lorem ipsum dolor sit amet", 15);

//     printf("After strlcat = %s\n returned strlen = %i\n", dest, i);
//  }

// char	destination[12] = "This ";
// char	tocat[10] = "is a cat.";
// char	*p_destination;
// char	*p_tocat;

// p_tocat = tocat;
// p_destination = destination;
// ft_strlcat(destination, tocat, 12);
// printf("%s\n", destination);
