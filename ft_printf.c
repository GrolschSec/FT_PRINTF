/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:43:20 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/07/20 15:18:03 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_args(va_list ap, const char *format, int *len)
{
	if (*format == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (*format == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (*format == 'p')
		ft_address(va_arg(ap, void *), len);
	else if (*format == 'd')
		ft_putnbr(va_arg(ap, int), len);
	else if (*format == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (*format == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int), len);
	else if (*format == 'x')
		ft_hexa(va_arg(ap, unsigned long long int), 0, len);
	else if (*format == 'X')
		ft_hexa(va_arg(ap, unsigned long long int), 1, len);
	else if (*format == '%')
		ft_putchar('%', len);
	else
		ft_putchar(*format, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	if (!format)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*format)
	{
		if (*format == '%')
			ft_printf_args(ap, ++format, &len);
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(ap);
	return (len);
}
