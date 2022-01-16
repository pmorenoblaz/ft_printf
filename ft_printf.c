#include "ft_printf.h"

int	ft_conversion(va_list args_list, char c)
{
	int	res;

	res = 1;
	if (c == 'c')
	{
		return (ft_putchr(va_arg(args_list, int)));
	}
	else if (c == 's')
		return (ft_putstr(va_arg(args_list, char *)));
	else if (c == 'p')
		return (0);
	else if (c == 'd')
		return (0);
	else if (c == 'i')
		return (0);
	else if (c == 'u')
		return (0);
	else if (c == 'x')
		return (0);
	else if (c == 'X')
		return (0);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args_list;
	int		pos[2];
	int		res;

	pos[0] = 0;
	pos[1] = 1;
	res = 0;
	va_start(args_list, str);
	while (str[pos[1]] != 0)
	{
		if (str[pos[0]] == '%')
		{
			if (str[pos[1]] == '%'){
				res += write(1, "%", 1);}
			else
			{	
				res += ft_conversion(args_list, str[pos[1]]);
			}
			pos[0]++;
			pos[1]++;
		}
		pos[0]++;
		pos[1]++;
	}
	va_end(args_list);
	return (res);
}
/*
int	main()
{
	int	res;
	int	res2;

	res = 0;
	res2 = 0;
//	ft_printf("%c", '0');
	printf("\n**********************\n");
	res = ft_printf("%c", '0');
	printf("\nNum de chars: %d\n", res);
	res2 = printf("%c", '0');
	printf("\nNum de chars printf: %d", res2);
	printf("\n**********************\n");
//	ft_printf(" %c ", '0');
	res = ft_printf(" %c", '0');
	printf("\nNum de chars: %d\n", res);
	res2 = printf(" %c", '0');
	printf("\nNum de chars printf: %d\n\n--------> Prueba real:\n", res2);
	printf("\n**********************\n");
// ft_printf(" %c", '0' - 256);
	res = ft_printf(" %c", '0' - 256);
	printf("\nNum de chars: %d\n", res);
	res2 = printf("%c", '0' - 256);
	printf("\nNum de chars printf: %d\n\n--------> Prueba real:\n", res2);
	printf("\n**********************\n");
// ft_printf("%c ", '0' + 256);
	res = ft_printf("%c ", '0' + 256);
	printf("\nNum de chars: %d\n", res);
	res2 = printf("%c", '0' + 256);
	printf("\nNum de chars printf: %d\n\n--------> Prueba real:\n", res2);
	printf("\n**********************\n");
//	ft_printf(" %c %c %c ", '0', 0, '1');
	res = ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\nNum de chars: %d\n", res);
	res2 = printf(" %c %c %c ", '0', 0, '1');
	printf("\nNum de chars printf: %d\n\n--------> Prueba real:\n", res2);
	printf("\n**********************\n");
//	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	res = ft_printf(" %c %c %c ", ' ', ' ', ' ');
	printf("\nNum de chars: %d\n", res);
	res2 = printf(" %c %c %c ", ' ', ' ', ' ');
	printf("\nNum de chars printf: %d\n\n--------> Prueba real:\n", res2);
	printf("\n**********************\n");
//	ft_printf(" %c %c %c ", '1', '2', '3');
	res = ft_printf(" %c %c %c ", '1', '2', '3');
	printf("\nNum de chars: %d\n", res);
	res2 = printf(" %c %c %c ", '1', '2', '3');
	printf("\nNum de chars printf: %d\n\n--------> Prueba real:\n", res2);
	printf("\n**********************\n");
//	ft_printf(" %c %c %c ", '2', '1', 0);
	res = ft_printf(" %c %c %c ", '2', '1', 0);
	printf("\nNum de chars: %d\n", res);
	res2 = printf(" %c %c %c ", '2', '1', 0);
	printf("\nNum de chars printf: %d\n\n--------> Prueba real:\n", res2);
	printf("\n**********************\n");
//	ft_printf(" %c %c %c ", 0, '1', '2');
	res = ft_printf(" %c %c %c ", 0, '1', '2');
	printf("\nNum de chars: %d\n", res);
	res2 = printf(" %c %c %c ", 0, '1', '2');
	printf("\nNum de chars printf: %d\n\n--------> Prueba real:\n", res2);
	printf("\n**********************\n");
}
*/