#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_putchr(const char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (write(1, "(null)", 6));
	while (str[i] != 0)
	{
		i += ft_putchr(str[i]);
	}
	return (i);
}
