/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:44:29 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/31 16:07:47 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static int	mode;

	if (!mode)
		mode = 0;
	if (sig == SIGUSR1 || sig == SIGUSR2)
		mode = transcribe(sig, mode);
	else if (sig == SIGINT)
	{
		ft_printf("Server terminated ... BYE!\n");
		kill(getpid(), SIGTERM);
	}
}

int	main(void)
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	signal(SIGINT, sig_handler);
	while (1)
		pause();
	return (0);
}
