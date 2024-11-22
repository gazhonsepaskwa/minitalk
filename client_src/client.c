/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/22 14:20:23 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int g_wait = FALSE;

void sig_hdlr(int sig)
{
	if (sig == SIGUSR1)
	{
		g_wait = FALSE;
		ft_printf("ack");
	}
}

void send_char(int pid, char c)
{
	int j;

	j = 8;
	while (j > 0)
	{
		while(g_wait == TRUE)
			usleep(1);
		if (((c >> (j - 1)) & 1) == 1)
		{
			kill(pid, SIGUSR2);
			usleep(50);
			g_wait = TRUE;
		}
		if (((c >> (j - 1)) & 1) == 0)
		{
			kill(pid, SIGUSR1);
			usleep(50);
			g_wait = TRUE;
		}
		j--;
	}
	return ;
}

static void	send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
}

static int base_check(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("%sInvalide usage: plz use the folowing structue :\n", RED);
		ft_printf("client <SRV_PID> <MSG>\n");
		return (0);
	}
	if (av[1] == NULL || av[2] == NULL)
	{
		ft_printf("%sNieter SRV_PID or MSG can be NULL", RED);
		return (0);
	}
	if (!onlydigit(av[1]))
	{
		ft_printf("%sInvalide PID please reffer to the server", RED);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	struct sigaction sa;

	if (base_check(ac, av) == FALSE)
		return (1);
	sa.sa_handler = sig_hdlr;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("%sSigaction error", RED);
		return (1);
	}
	send_message(ft_atoi(av[1]), av[2]);
	return (0);
}
