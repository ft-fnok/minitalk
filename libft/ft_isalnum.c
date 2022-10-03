/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:50:50 by nlalleike         #+#    #+#             */
/*   Updated: 2021/11/18 21:15:25 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	isalnum;

	isalnum = 0;
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
	{
		isalnum = 1;
	}
	return (isalnum);
}

// #include <stdio.h>
// int main(void)
// {
// 	char c;

// 	c = ' ';
// 	printf("%d", ft_isalnum(c));
// }