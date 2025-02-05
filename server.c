#include <signal.h>
#include <unistd.h>

void	handler(int sig, siginfo_t *info, void *content)
{
	static int	pid = 0;
	static int	i = 0;
	static char unsigned	chr = 0;

	(void)content;
	if (!pid)
		pid = info->si_pid;
	chr |= (sig == SIGUSR2);
	if (i++ == 8)
	{
		i = 0;
		ft_putchar_fd(chr, 1);
		chr = 0;
	}
	else
		chr <<= 1;
}
int	main(void)
{
	struct sigaction sa;

	sa.sa_handler = handler;
	ft_printf("Server PID:%d", getpid());
	while (2137)
	{
		pause ();
	}
	return (0);
}
