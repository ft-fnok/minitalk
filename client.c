/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:44:35 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/02 17:35:58 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char const *argv[])
{
	int pid;
	int	w_count;
	int c_count;
	int len;

	w_count = 2;
	c_count = 0;
	len = 0;
	pid = ft_atoi(argv[1]);
	ft_printf("PID received: %i\nNo. of args to print: %i\n", pid, (argc - 2));

	while (w_count < argc)
	{
		len = ft_strlen(argv[w_count]);
		while (c_count < len)
		{
			send(pid, binval(argv[w_count][c_count]))
			c_count++;
		}
		c_count = 0;
		w_count++;
	}
	
	return (0);
}
