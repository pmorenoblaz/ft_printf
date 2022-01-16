/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:02:48 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/01/16 17:57:47 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchr(const char c);
int	ft_putstr(const char *str);
int	ft_strlen(const char *str);
int	ft_putnbr(int nbr, char *base, char c);
int	ft_putnbr_base(unsigned long int nbr, char *base);
int	ft_unsig_putnbr_base(unsigned long int nbr, char *base);
int	ft_printf(const char *str, ...);

#endif
