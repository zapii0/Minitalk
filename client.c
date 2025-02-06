/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:11:48 by mzapora           #+#    #+#             */
/*   Updated: 2025/02/06 13:15:38 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

void	received(int sig, siginfo_t *info, void *content)
{
	(void)content;
	(void)info;
	if (sig == SIGUSR2)
		ft_printf("%s\n", "Server received message");
	return ;
}

void	send_message(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
	bit = 8;
}

int	main(int ac, char **av)
{
	int					pid;
	char				c;
	struct sigaction	sc;

	sc.sa_sigaction = received;
	sigaction(SIGUSR2, &sc, 0);
	c = '\n';
	pid = 0;
	if (ac != 3 || !ft_strlen(av[2]))
		return (ft_printf("Wrong argument\n"));
	pid = ft_atoi(av[1]);
	while (*av[2])
		send_message(pid, (*av[2]++));
	send_message(pid, c);
	send_message(pid, '\0');
}
