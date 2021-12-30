#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (write(1, "null", 4));
	while (str[i] != 0)
	{
		i += ft_putchar(str[i]);
	}
	return (i);
}