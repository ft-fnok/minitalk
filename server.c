/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:44:29 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/30 21:51:01 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	ft_printf("Handler ...\n");
	if (sig == SIGUSR1 || sig == SIGUSR2)
		transcribe(sig);
	else if (sig == SIGINT)
	{
		ft_printf("Server terminated ... BYE!\n");
		kill(getpid(), SIGTERM);
	}
}

void	transcribe(int sig)
{
	static int 	count;
	static char	*c;
	int			i;
	int			nbr;

	ft_printf("Transcriber ...\n");
	if (c == NULL)
	{
		ft_printf("c = NULL, callocing memory ...\n");
		c = ft_calloc(9, sizeof(char));
	}
	if (!count)
	{
		ft_printf("count = NULL, initializing ...\n");
		count = 0;
	}
	i = 0;
	nbr = 0;
	if (sig == SIGUSR1)
	{
		c[count] = 0;
		ft_printf("Sig 1\n");
	}
	else if (sig == SIGUSR2)
	{
		c[count] = 1;
		ft_printf("Sig 2\n");
	}
	count++;
	ft_printf("count = %i ...\n", nbr);

	if (count % 8 == 0)
	{
		while (count > 0)
		{
			nbr += (c[count - 1] + 48) * (2 * i);
			i++;
			count--;
			ft_printf("nbr: %i\n", nbr);
		}
		write(1, &nbr, 1);
		free(c);
		c = NULL;
	}
}

int main(void)
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	signal(SIGINT, sig_handler);
	while (1)
		pause();
	return (0);
}