/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:52:41 by nlalleike         #+#    #+#             */
/*   Updated: 2021/11/18 12:58:48 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	isalpha;

	isalpha = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		isalpha = 1;
	}
	return (isalpha);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char c;
// 	c = '1';
// 	printf("%d", ft_isalpha(c));
// 	return (0);
// }