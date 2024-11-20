/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/20 16:41:27 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int g_wait = FALSE;

static int	onlydigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

static int	onlyprintable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isprint(str[i++]))
			return (0);
	return (1);
}

static void	send_message(int pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i])
	{
		j = 8;
		while (j > 0)
		{
			if (((msg[i] >> (j - 1)) & 1) == 1)
			{
				kill(pid, SIGUSR2);
				usleep(50);
			}
			if (((msg[i] >> (j - 1)) & 1) == 0)
			{
				kill(pid, SIGUSR1);
				usleep(50);
			}
			j--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("%sInvalide usage: plz use the folowing structue :\n", RED);
		ft_printf("client <SRV_PID> <MSG>\n");
		return (1);
	}
	if (av[1] == NULL || av[2] == NULL)
	{
		ft_printf("%sNieter SRV_PID or MSG can be NULL", RED);
		return (1);
	}
	if (!onlydigit(av[1]))
	{
		ft_printf("%sInvalide PID please reffer to the server", RED);
		return (1);
	}
	send_message(ft_atoi(av[1]), av[2]);
	return (0);
}
