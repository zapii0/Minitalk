/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:12:01 by mzapora           #+#    #+#             */
/*   Updated: 2025/02/06 13:16:26 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

void	handler(int sig, siginfo_t *info, void *content)
{
	static int				pid = 0;
	static int				i = 0;
	static char unsigned	chr = 0;

	(void)content;
	if (!pid)
		pid = info->si_pid;
	chr |= (sig == SIGUSR2);
	if (i++ == 7)
	{
		i = 0;
		if (!chr)
		{
			kill(pid, SIGUSR2);
			pid = 0;
			return ;
		}
		ft_putchar_fd(chr, 1);
		chr = 0;
	}
	else
		chr <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %u\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (2137)
	{
		pause ();
	}
	return (0);
}
