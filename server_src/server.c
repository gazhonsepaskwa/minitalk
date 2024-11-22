/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:25 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/22 14:29:11 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sig_hdlr(int sig, siginfo_t* info, void *context)
{
	static int	i;
	static int	c;

	(void)context;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		c = c << 1;
		if (sig == SIGUSR2)
			c += 1;
		i++;
		if (i == 8)
		{
			write(1, &c, 1);
			i = 0;
			c = 0;
		}
	}
		ft_printf("[DEBUG]");

	kill(info->si_pid, SIGUSR1);
		ft_printf("[DEBUG]");
}


int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_sigaction = sig_hdlr;
	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
	{
		ft_printf("%sSigaction error", RED);
		return (1);
	}
	sa2.sa_sigaction = sig_hdlr;
	sigemptyset(&sa2.sa_mask);
	sa2.sa_flags = 0;
	if (sigaction(SIGUSR2, &sa2, NULL) == -1)
	{
		ft_printf("%sSigaction error", RED);
		return (1);
	}
	ft_printf("Prossess id : %d\n", (int)getpid());
	while (1)
		pause();
	return (0);
}
