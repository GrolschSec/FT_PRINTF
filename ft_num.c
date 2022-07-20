/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:44:58 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/07/19 15:47:09 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	long long int	nb;
	char			res;

	nb = n;
	if (nb == -2147483648)
		ft_putstr("-2147483648", len);
	else if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', len);
		ft_putnbr(nb, len);
	}
	if (nb < 10)
	{
		res = nb + 48;
		ft_putchar(res, len);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}

void	ft_putnbr_unsigned(unsigned int nb, int *len)
{
	char	res;

	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', len);
		ft_putnbr_unsigned(nb, len);
	}
	else if (nb < 10)
	{
		res = nb + 48;
		ft_putchar(res, len);
	}
	else if (nb > 9)
	{
		ft_putnbr_unsigned(nb / 10, len);
		ft_putnbr_unsigned(nb % 10, len);
	}
}

void	ft_hexa(unsigned long long int n, int mode, int *len)
{
	char	*base16_min;
	char	*base16_max;
	char	*choice;

	base16_min = "0123456789abcdef";
	base16_max = "0123456789ABCDEF";
	if (mode == 0)
		choice = base16_min;
	else if (mode == 1)
		choice = base16_max;
	if (n > 16)
	{
		ft_hexa(n / 16, mode, len);
		ft_putchar(choice[n % 16], len);
	}
	else if (n < 16)
		ft_putchar(choice[n], len);
}

void	ft_address(void *ptr, int *len)
{
	unsigned long long	adr;
	
	if (!ptr)
		ft_putstr("(nill)", len);
	else
	{
		adr = (unsigned long long) ptr;
		ft_putstr("0x", len);
		ft_hexa(adr, 0, len);
	}
}
