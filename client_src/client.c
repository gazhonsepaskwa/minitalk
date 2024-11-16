/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/16 16:20:43 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int  onlydigit(char *str)
{
    int i;

    i = 0;
    while (str[i])
        if (!ft_isdigit(str[i++]))
            return (0);
    return (1);
}

static int  onlyprintable(char *str)
{
    int i;

    i = 0;
    while (str[i])
        if (!ft_isprint(str[i++]))
            return (0);
    return (1);
}

static void send_message(int pid, char *msg)
{
    int i;
    int j;

    i = 0;
    while(msg[i])
    {
        j = 0;
        while (j < 8)
        {
            if ((msg[i] & 1) == 1)
            {
                kill(pid, SIGUSR2);
            }
            if ((msg[i] & 1) == 0)
            {
                kill(pid, SIGUSR1);
            }
            msg[i] = msg[i] >> 1;
            i++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        ft_printf("%sInvalide usage: plz use the folowing structue :\n", RED);
        ft_printf("client <SRV_PID> <MSG>\n");
        return(1);
    }
    if (av[1] == NULL || av[2] == NULL)
    {
        ft_printf("%sNieter SRV_PID or MSG can be NULL", RED);
        return(1);
    }
    if (!onlydigit(av[1]))
    {
        ft_printf("%sInvalide PID please reffer to the server", RED);
        return(1);
    }
    if (!onlyprintable(av[2]))
    {
        ft_printf("%sInvalide MSG : not only printable char", RED);
        return(1);
    }
    send_message(ft_atoi(av[1]), av[2]);
    return(0);
}
