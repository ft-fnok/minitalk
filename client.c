/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:44:35 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/30 18:05:18 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void	send(int pid, char *c)
{
	int n;

	n = 0;
	while (n < 8)
	{
		if (c[n] == '0')
			kill(pid, SIGUSR1);
		else if (c[n] == '1')
			kill(pid, SIGUSR2);
		n++;
		usleep(100);
	}
}

char	*binval(int c)
{
	unsigned int	i;
	int				count;
	int				n;
	char			*bin;
	char			rev_bin[9];

	bin = ft_calloc(9, sizeof(char));
	bin[8] = '\0';
	rev_bin[8] = '\0';
	i = 0;
	count = c;
	n = 0;
	while (n < 8)
	{
		rev_bin[n] = (c % 2) + 48;
		c /= 2;
		n++;
	}
	while (n > 0)
	{
		bin[i] = rev_bin[n - 1];
		n--;
		i++;
	}
	return (bin);
}

int main(int argc, char const *argv[])
{
	int 	pid;
	int 	c_count;
	int 	len;
	char	*c;

	c_count = 0;
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	ft_printf("PID received: %i\nNo. of args to print: %i\n", pid, (argc - 2));
	ft_printf("Arg received: %s\n", argv[(argc - 1)]);
	ft_printf("Len of string: %i\n", len);

	while (c_count < len)
	{
		c = binval(argv[2][c_count]);
		ft_printf("Bin: %s\n", c);
		send(pid, c);
		free(c);
		c_count++;
	}
	return (0);
}
