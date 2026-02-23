/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpinh <andrpinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:48:01 by andrpinh          #+#    #+#             */
/*   Updated: 2026/02/23 18:44:55 by andrpinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_puthex(unsigned long n, int uppercase)
{
	char	*base;
	int		count;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
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
		return (write(1, "(nil)", 5)); // ponteiro NULL → nil

	addr = (unsigned long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthex(addr, 0);
	return (count);
}
