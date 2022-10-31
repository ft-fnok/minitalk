/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:39:14 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/31 14:13:23 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "./printf/libftprintf.h"

//client functions
char	*binval(int c);
void	confirmed(int sig);
void	send_signature(int pid);
void	send(int pid, char *c);

//server functions
int		transcribe(int sig, int mode);
//int		transcribe(int sig);
void	sig_handler(int sig);
void	collector(int sig, int count, char *c);
int		transliterator(char *c, int count, int i, int mode);
int		writeout(int nbr);
int		safe_pid(int nbr);
