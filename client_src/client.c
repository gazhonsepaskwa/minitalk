/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/25 15:21:46 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int g_wait = FALSE;

void sig_hdlr(int sig)
{
	if (sig == SIGUSR1)
	{
		g_wait = FALSE;
		//ft_printf(" ack ");
	}
}

int	send_char(int pid, char c)
{
	int j;
	int i;

	j = 8;
	while (j > 0)
	{
		while(g_wait == TRUE)
		{
			pause();
		}
		if (((c >> (j - 1)) & 1) == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
			g_wait = 2;
		}
		if (((c >> (j - 1)) & 1) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
			g_wait  = 2;
		}
		i = 0;
		while (++i < 3)
		{
			if (g_wait == FALSE)	
				break;
			sleep(1);	
		}

		if (g_wait == FALSE)
			j--;
	}
	return (0);
}

static int	send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		if (send_char(pid, msg[i]) == -1)
			return (-1);
		i++;
	}
	send_char(pid, '\0');
	return (0);
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
