/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:13:35 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/25 06:01:26 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"

int	ft_printf(const char *fstr, ...);

int	ft_put_c(char c);
int	ft_put_s(char *s);
int	ft_put_i(int n);
int	ft_put_ui(unsigned int n);
int	ft_put_ui_base(unsigned int nbr, char *base);
int	ft_put_uli_base(unsigned long int nbr, char *base);

#endif
