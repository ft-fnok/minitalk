/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:14:28 by nlalleike         #+#    #+#             */
/*   Updated: 2021/12/19 11:34:35 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joint = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!joint)
		return (NULL);
	ft_strlcpy(joint, s1, s1_len + 1);
	ft_strlcat(&joint[s1_len], s2, s2_len + 1);
	return (joint);
}
