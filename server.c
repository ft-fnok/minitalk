/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:44:29 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/03 17:29:16 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	transcribe(int sig, char *string)
{
	if (sig == SIGUSR1)
		

}

int main(void)
{
	char	*string;

	string = ft_calloc(1, sizeof(char));
	ft_printf("PID: %i\n", getpid());
	
	signal(SIGINT, transcribe);
	return (0);
}