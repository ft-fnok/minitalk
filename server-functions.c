/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server-functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:55:00 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/31 17:46:40 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	transcribe(int sig, int mode)
{
	static int	count;
	static char	c[9];
	int			nbr;
	int			i;

	if (!count)
		count = 0;
	i = 0;
	nbr = 0;
	collector(sig, count, c);
	count++;
	if (count % 8 == 0)
	{
		mode = transliterator(c, count, i, mode);
		count = 0;
	}
	return (mode);
}

int	transliterator(char *c, int count, int i, int mode)
{
	int	bin;
	int	nbr;

	nbr = 0;
	bin = ft_atoi(c);
	while (count > 0)
	{
		if (i == 0)
		{
			nbr = bin % 10;
			bin /= 10;
			i = 2;
		}
		else
		{
			nbr += (bin % 10) * i;
			bin /= 10;
			i *= 2;
		}
		count--;
	}
	if (mode == 0)
		return (writeout(nbr));
	return (safe_pid(nbr));
}

int	safe_pid(int nbr)
{
	static int	run;
	static char	pid[8];

	if (!run)
		run = 0;
	pid[run] = nbr;
	if (nbr == 0)
	{
		kill(ft_atoi(pid), SIGUSR2);
		run = 0;
		return (0);
	}
	run++;
	return (1);
}

void	collector(int sig, int count, char *c)
{
	if (sig == SIGUSR1)
		c[count] = '0';
	else if (sig == SIGUSR2)
		c[count] = '1';
}

int	writeout(int nbr)
{
	int	mode;

	mode = 0;
	if (nbr == 0)
	{
		nbr = '\n';
		mode = 1;
	}
	write(1, &nbr, 1);
	return (mode);
}
