#include "ft_printf.h"

int	ft_putnbr(int nbr, char *base, char c)
{
	int				cont;
	unsigned int	unbr;
	unsigned int	blength;

	cont = 0;
	blength = 0;
	blength = ft_strlen(base);
	if (nbr < 0)
	{
		if (c != 'u')
			cont += write(1, "-", 1);
		nbr = nbr * (-1);
	}
	unbr = nbr;
	if (unbr >= blength)
		cont += ft_putnbr_base(unbr / blength, base, c);
	cont += ft_putchr(base[unbr % blength]);
	return (cont);
}

int	ft_putnbr_base(unsigned long int nbr, char *base, char c)
{
	int				cont;
	unsigned int	unbr;
	unsigned int	blength;

	cont = 0;
	blength = 0;
	blength = ft_strlen(base);
	if (nbr < 0)
	{
		if (c != 'u')
			cont += write(1, "-", 1);
		nbr = nbr * (-1);
	}
	unbr = nbr;
	if (unbr >= blength)
		cont += ft_putnbr_base(unbr / blength, base, c);
	cont += ft_putchr(base[unbr % blength]);
	return (cont);
}