/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:25 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/20 16:38:51 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int g_wait = FALSE;

void	sig_hdlr(int sig)
{
	static int	i;
	static int	c;

	if (sig == SIGUSR2)
	{
		i++;
		c = c << 1;
		c += 1;
		//ft_printf("[DEBUG] 1\n");
	}
	if (sig == SIGUSR1)
	{
		i++;
		c = c << 1;
		//ft_printf("[DEBUG] 0\n");
	}
	if (i == 8)
	{
		//t_printf("[DEBUG] print char ascii = {%d}\n\n", c);
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}


int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_handler = sig_hdlr;
	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
	{
		ft_printf("%sSigaction error", RED);
		return (1);
	}
	sa2.sa_handler = sig_hdlr;
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
