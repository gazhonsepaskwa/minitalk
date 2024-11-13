/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:39:28 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/13 15:50:53 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_put_ui_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				count;
	int				tmp;

	count = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	if (nbr >= base_len)
	{
		tmp = ft_put_ui_base(nbr / base_len, base);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	tmp = write(1, &base[nbr % base_len], 1);
	if (tmp == -1)
		return (-1);
	return (tmp + count);
}

int	ft_put_uli_base(unsigned long int nbr, char *base)
{
	unsigned long	base_len;
	int				count;
	int				tmp;

	count = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	if (nbr >= base_len)
		count += ft_put_uli_base(nbr / base_len, base);
	tmp = write(1, &base[nbr % base_len], 1);
	if (tmp == -1)
		return (-1);
	return (tmp + count);
}

int	ft_put_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_s(char *s)
{
	if (!s)
		return (ft_put_s("(null)"));
	return (write(1, s, ft_strlen(s)));
}
