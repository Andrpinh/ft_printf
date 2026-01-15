/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpinh <andrpinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:24:38 by andrpinh          #+#    #+#             */
/*   Updated: 2025/12/08 14:08:46 by andrpinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *string, ...)
{
	va_list var;
	int	count;

	va_start(var, string);
	count = 0;
	while (*string)
	{
		if (*string == '%')
		{
			string ++;
			count += print_format(*string,var);
		}
		else
			count += write(1, string, 1);
		string ++;
		
	}
	va_end(var);
	return(count);
}

int	print_format(char c, va_list var)
{
	if (c == 'c')
		return (ft_putchar(va_arg(var, int)));
	if (c == 's')
		return (ft_putstr(va_arg(var, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(var, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(var, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(var, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(var, unsigned int), 1));
	if (c == 'p')
		return (ft_putptr(va_arg(var, void *)));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
