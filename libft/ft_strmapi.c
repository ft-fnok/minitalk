/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:10:09 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/19 22:43:16 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	string = ft_calloc(len + 1, sizeof(char));
	if (!string)
		return (NULL);
	while (len > 0)
	{
		string[len - 1] = f(len - 1, s[len - 1]);
		len--;
	}
	return (string);
}
