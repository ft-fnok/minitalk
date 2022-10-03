/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:54:03 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/05 20:35:50 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (!ft_isascii(c))
		return ((char *)s);
	len = ft_strlen((char *)s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	str[] = "This is a";
// 	char	*p_return;
// 	p_return = ft_strrchr(str, 't');
// 	printf("%s\n", p_return);
// }