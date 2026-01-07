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
}
int	print_format(char c, va_list var)
{
	if (c == 'c')
		return (ft_putchar(va_arg(var, int)));
	if (c == 's')
		return ();
	if (c == 'd' || c == 'i')
		return ();
	if (c == 'u')
		return ();
	if (c == 'x' || c == 'X')
		return ();
	if (c == 'p')
		return ();
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
