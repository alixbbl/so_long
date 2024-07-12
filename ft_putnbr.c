/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:56:20 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/03 17:35:51 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int numb)
{
	unsigned long	i;
	int				ret;

	i = 0;
	ret = 0;
	if (numb > 9)
	{
		i += ft_putnbr(numb / 10);
		i += ft_putnbr(numb % 10);
	}
	else if (numb < 0)
	{
		ret += ft_putchar('-');
		numb *= -1;
		i += ft_putnbr(numb);
	}
	else
	{
		ret += ft_putchar(48 + numb);
		i++;
	}
	return (i + ret);
}

unsigned int	ft_putnbr_uns(unsigned int numb)
{
	unsigned long	i;
	int				ret;

	i = 0;
	ret = 0;
	if (numb == 2147483647)
	{
		ret += write(1, "2147483647", 10);
		return (10);
	}
	if (numb > 9)
	{
		i += ft_putnbr(numb / 10);
		i += ft_putnbr(numb % 10);
	}
	else
	{
		ret += ft_putchar(48 + numb);
		i++;
	}
	return (i + ret);
}

unsigned int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	unsigned long	i;

	i = 0;
	if (nbr >= 16)
		i += ft_putnbr_hex(nbr / 16, base);
	i += ft_putchar(base[nbr % 16]);
	return (i);
}
