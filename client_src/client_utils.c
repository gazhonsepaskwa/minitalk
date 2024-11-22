/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:46:58 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/22 14:10:03 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	onlydigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}