/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpinh <andrpinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:24:35 by andrpinh          #+#    #+#             */
/*   Updated: 2025/12/08 15:00:37 by andrpinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned int n, int uppercase)
{
	char	*base;
	int		count;

	base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
		return (write(1, "0x0", 3));
	addr = (unsigned long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthex(addr, 0);
	return (count);
}
