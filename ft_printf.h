/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:29:19 by alibourb          #+#    #+#             */
/*   Updated: 2023/03/29 17:03:52 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_printf(const char *str, ...);
int				ft_putnbr(int numb);
unsigned int	ft_hexa(unsigned long nbr);
unsigned int	ft_putnbr_uns(unsigned int numb);
unsigned int	ft_putnbr_hex(unsigned int nbr, char *base);
unsigned int	ft_putptr(void *ptr);
unsigned int	ft_print_arg(const char c, va_list ap);
void			ft_putptr_hex(unsigned long l_ptr, char *base);
void			ft_putchar_ptr(int c);

#endif
