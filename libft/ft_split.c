/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:07:05 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/19 15:16:01 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_count(const char *s, const char c)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

static size_t	w_len(const char *s, const char c)
{
	size_t	n;

	n = 0;
	while (s[n] != c && s[n] != '\0')
		n++;
	return (n);
}

static char	*make_str(const char *s, size_t len)
{
	char	*str;

	str = (char *)ft_calloc(len + 1, sizeof(char));
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = s[len - 1];
		len--;
	}
	return (str);
}

static char	**fill_strs(const char *s, char **strs, char c)
{
	size_t	w;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	w = 0;
	while (i < len)
	{
		while (s[i] == c && i < len)
			i++;
		if (s[i] != c && i < len)
		{
			strs[w] = make_str(&s[i], w_len(&s[i], c));
			w++;
		}
		while (s[i] != c && i < len)
			i++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**strs;

	if (!s)
		return (NULL);
	n = n_count(s, c);
	strs = (char **)ft_calloc((n + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	strs = fill_strs(s, strs, c);
	strs[n] = NULL;
	return (strs);
}
