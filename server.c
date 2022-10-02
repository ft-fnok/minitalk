/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:44:29 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/02 16:08:31 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{	
	int	pid;
	
	pid = getpid();
	ft_printf("PID: %i\n", pid);
	
	return (0);
}