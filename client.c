#include <unistd.h>
#include <signal.h>
#include "libft.h"

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
		usleep(100);
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = 0;
	if (ac != 3 || !ft_strlen(av[2]))
		return (ft_printf("Wrong argument\n"));
	ft_printf("Waiting for arguments\n");
	pid = ft_atoi(av[1]);
	while (*av[2])
		send_message(pid, (*av[2]++));
	return (0);
}
