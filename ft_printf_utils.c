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

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	int count = 0;

    if (!s)
        s = "(null)";
    while (*s)
    {
        write(1, s, 1);
        s++;
        count++;
    }
    return (count);
}
