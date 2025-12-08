/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrpinh <andrpinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:24:57 by andrpinh          #+#    #+#             */
/*   Updated: 2025/12/08 14:01:40 by andrpinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *string, ...);
int print_format(char c, va_list args);

int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);
int ft_putunsigned(unsigned int n);
int ft_puthex(unsigned int n, char c);
int ft_putptr(unsigned long long n);

#endif