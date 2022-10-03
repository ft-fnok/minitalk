/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:59:17 by nlalleike         #+#    #+#             */
/*   Updated: 2021/12/17 22:35:44 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int	isdigit;

	isdigit = 0;
	if (c >= '0' && c <= '9')
	{
		isdigit = 1;
	}
	return (isdigit);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char c;
// 	c = ' ';
// 	printf("%d", ft_isdigit(c));
// 	return (0);
// }