/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@students.42wolfsbur    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:40:26 by nlalleik          #+#    #+#             */
/*   Updated: 2021/11/28 18:23:19 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*a;

	a = s;
	while (n > 0)
	{
		a[n - 1] = c;
		n--;
	}
	return (s);
}

// #include <stdio.h>
// int main(void)
// {
// 	int	i;
// 	int	*i_ptr;
// 	char c[20] = "there ain't nothing "
//
// 	i = 123;
// 	i_ptr = i;
//
// 	printf("i = %i\n", )
// }