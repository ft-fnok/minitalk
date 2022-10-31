/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:44:35 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/31 16:02:36 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirmed(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message received.\n");
}

void	send(int pid, char *c)
{
	int	n;

	n = 0;
	while (n < 8)
	{
		if (c[n] == '0')
			kill(pid, SIGUSR1);
		else if (c[n] == '1')
			kill(pid, SIGUSR2);
		n++;
		usleep(200);
	}
}

void	send_signature(int pid)
{
	int		c_count;
	char	*c;
	char	*char_pid;
	int		len;

	signal(SIGUSR2, confirmed);
	char_pid = ft_itoa(getpid());
	c_count = 0;
	len = ft_strlen(char_pid);
	while (c_count < len)
	{
		c = binval(char_pid[c_count]);
		send(pid, c);
		free(c);
		c_count++;
	}
	c = binval('\0');
	send(pid, c);
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

int	main(int argc, char const *argv[])
{
	int		pid;
	int		c_count;
	int		len;
	char	*c;

	if (argc < 3)
	{
		write(2, "Error: Nothing to send.\n", 24);
		return (0);
	}
	c_count = 0;
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	while (c_count < len)
	{
		c = binval(argv[2][c_count]);
		send(pid, c);
		free(c);
		c_count++;
	}
	c = binval('\0');
	send(pid, c);
	send_signature(pid);
	return (0);
}
