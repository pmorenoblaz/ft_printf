#include "ft_printf.h"

int	ft_putchr(const char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (write(1, "null", 4));
	while (str[i] != 0)
	{
		i += ft_putchr(str[i]);
	}
	return (i);
}