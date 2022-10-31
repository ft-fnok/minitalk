/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:44:29 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/31 15:24:42 by nlalleik         ###   ########.fr       */
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



// previous version without PID

// int	transcribe(int sig)
// {
// 	static int 	count;
// 	static char	*c;
// 	int			i;
// 	int			nbr;

// 	if (c == NULL)
// 		c = ft_calloc(9, sizeof(char));
// 	if (!count)
// 		count = 0;
// 	i = 0;
// 	nbr = 0;
// 	collector(sig, count, c);
// 	count++;
// 	if (count % 8 == 0)
// 		i = transliterator(c, count, i);
// 	return (i);
// }

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