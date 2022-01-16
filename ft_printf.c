#include "ft_printf.h"

int	ft_conversion(va_list args_list, char c)
{
	int	res;

	res = 1;
	if (c == 'c')
		return (ft_putchr(va_arg(args_list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args_list, char *)));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		res = ft_putnbr_base(va_arg(args_list, unsigned long int), "0123456789abcdef", c);
		return (res + 2);
	}
	else if (c == 'd')
		return (ft_putnbr(va_arg(args_list, int), "0123456789", c));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args_list, int), "0123456789", c));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(args_list, int), "0123456789", c));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args_list, int), "0123456789abcdef", c));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args_list, int), "0123456789ABCDEF", c));
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

// int	main()
// {
// 	int	res;
// 	int	res2;
// 	void	*ptr;

// 	ptr = malloc(17);

// printf("%p\n",ptr);

// 	res = 0;
// 	res2 = 0;
// 	printf("\n**********************\n");
// 	res = ft_printf(" %p ", 15);
// 	printf("\nNum de chars: %d\n", res);
// 	res2 = printf(" %p ", 15);
// 	printf("\nNum de chars printf: %d", res2);
// 	printf("\n**********************\n");
// 	return (0);
// }
