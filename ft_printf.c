/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:36:27 by maralves          #+#    #+#             */
/*   Updated: 2025/09/06 03:33:47 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	int		i;
	int		chars_printed;
	unsigned long long x;
	
	i = 0;	
	chars_printed = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				chars_printed += ft_putchar(va_arg(args, int));
			if (str[i + 1] == 's')
				chars_printed += ft_putstr(va_arg(args, char *));
			if (str[i + 1] == 'p')
			{
				x = (unsigned long long)va_arg(args, void *);
				if (x == 0)
				{
					write (1, "(nil)", 5);
					chars_printed += 5;
				}
				else
				{
				write (1,"0x",2);
				chars_printed += 2;
				chars_printed += ft_putnbr_hex(x, 'l');			
				}
			}	
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				chars_printed += ft_putnbr(va_arg(args, int));			
			if (str[i + 1] == 'u')
				chars_printed += ft_putnbr_unsigned(va_arg(args, unsigned int));			
			if (str[i + 1] == 'x')
				chars_printed += ft_putnbr_hex((unsigned long long)va_arg(args, unsigned int), 'l');
			if (str[i + 1] == 'X')
				chars_printed += ft_putnbr_hex((unsigned long long)va_arg(args, unsigned int), 'u');
			if (str[i + 1] == '%')
				chars_printed += ft_putchar('%');
			i++;			
		}
		else
			chars_printed += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (chars_printed);
}
