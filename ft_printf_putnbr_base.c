#include "ft_printf.h"

int	ft_putnbr_base(int nbr, char *base)
{
	int				cont;
	unsigned int	unbr;
	unsigned int	blength;
	int				s;

	cont = 0;
	blength = 0;
	while (base[blength] != 0)
		blength++;
	if (nbr < 0)
	{
		cont += write(1, "-", 1);
		nbr = nbr * (-1);
	}
	unbr = nbr;
	//Cambiar esta parte ¿Meter puntero?
	if (unbr >= blength)
		ft_putnbr_base(unbr/blength, base);
	cont += ft_putchar(base[unbr % blength]);
	return (cont);
}
