/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:29:46 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/03 17:25:25 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	ret;

	if (!str)
	{
		ret = write(1, "(null)", 6);
		if (ret == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ret = write(1, &str[i], 1);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (i);
}

unsigned int	ft_print_arg(const char c, va_list ap)
{
	unsigned int	i;

	i = 0;
	if (c == '%')
		i += ft_putchar('%');
	else if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		i += (ft_putptr((va_arg(ap, void *))));
	else if ((c == 'd') || (c == 'i'))
		i += (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		i += ft_putnbr_uns(va_arg(ap, unsigned int));
	else if ((c == 'x') || (c == 'X'))
	{
		if (c == 'x')
			i += ft_putnbr_hex((va_arg(ap, unsigned int)), "0123456789abcdef");
		else if (c == 'X')
			i += ft_putnbr_hex((va_arg(ap, unsigned int)), "0123456789ABCDEF");
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_print_arg(str[i + 1], ap);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
