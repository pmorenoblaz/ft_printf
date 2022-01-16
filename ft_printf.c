/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:57:02 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/01/16 17:57:06 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list args_list, char c)
{
	if (c == 'c')
		return (ft_putchr(va_arg(args_list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args_list, char *)));
	else if (c == 'p')
		return (write(1, "0x", 2) + ft_putnbr_base
			(va_arg(args_list, unsigned long int), "0123456789abcdef"));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args_list, int), "0123456789", c));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args_list, int), "0123456789", c));
	else if (c == 'u')
		return (ft_unsig_putnbr_base(va_arg(args_list, int), "0123456789"));
	else if (c == 'x')
		return (ft_unsig_putnbr_base(va_arg(args_list, int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_unsig_putnbr_base(va_arg(args_list, int),
				"0123456789ABCDEF"));
	else
		return (ft_putchr(c));
}

int	ft_printf(const char *str, ...)
{
	va_list	args_list;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(args_list, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			if (i + 1 < ft_strlen(str))
				res += ft_conversion(args_list, str[i + 1]);
			i++;
		}
		else
		{
			res += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args_list);
	return (res);
}
