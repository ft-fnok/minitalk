/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:39:14 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/30 20:38:44 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "./printf/libftprintf.h"

//client functions
char	*binval(int c);
void	send(int pid, char *c);
void	transcribe(int sig);
void	sig_handler(int sig);
