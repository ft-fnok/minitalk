/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:11:12 by nlalleik          #+#    #+#             */
/*   Updated: 2021/11/25 15:59:15 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;

	a = (char *)s;
	while (n > 0)
	{
		a[(n - 1)] = '\0';
		n--;
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	int		i = -123;
// 	float	f = 123124.23234;
// 	int		*p_i;
// 	float	*p_f;
// 	char	c[] = "this is something";
//
// 	p_i = &i;
// 	p_f = &f;
// 	printf("T0[c]: %s\n", c);
// 	printf("T0[i]: %d\n", i);
// 	printf("T0[f]: %f\n", f);
// 	ft_bzero(c, sizeof(c));
// 	ft_bzero(p_i, sizeof(i));
// 	ft_bzero(p_f, sizeof(f));
// 	printf("T1[c]: %s\n", c);
// 	printf("T1[i]: %d\n", i);
// 	printf("T1[f]: %f\n", f);
// }
