/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:31:08 by nlalleike         #+#    #+#             */
/*   Updated: 2021/11/18 21:13:48 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	int	isascii;

	isascii = 0;
	if (c >= 0 && c <= 127)
	{
		isascii = 1;
	}
	return (isascii);
}

// #include <stdio.h>
// int main(void)
// {
// 	char c;
// 	c = '0';
// 	printf("%d, value = %d", ft_isascii(c), (int) c);
// 	return(0);
// }