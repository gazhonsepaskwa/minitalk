/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:25 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/16 16:20:39 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void sigusr2_hdlr()
{
    ft_printf("1");
}

void sigusr1_hdlr()
{
    ft_printf("0");
}

int main(void)
{
    struct sigaction sa1;
    struct sigaction sa2;

    sa1.sa_handler = sigusr1_hdlr;
    sigemptyset(&sa1.sa_mask);
    sa1.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa1, NULL) == -1)
    {
        ft_printf("%sSigaction error", RED);
        return (1);
    }
    sa2.sa_handler = sigusr2_hdlr;
    sigemptyset(&sa2.sa_mask);
    sa2.sa_flags = 0;
    if (sigaction(SIGUSR2, &sa2, NULL) == -1)
    {
        ft_printf("%sSigaction error", RED);
        return (1);
    }
    ft_printf("Prossess pid : %d\n", (int)getpid());
    while (1)
        pause();
    return (0);
}
