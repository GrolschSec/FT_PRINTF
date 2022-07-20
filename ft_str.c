/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:03:59 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/07/20 16:38:31 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	if (s == NULL)
	{
		ft_putstr("(null)", len);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
}
