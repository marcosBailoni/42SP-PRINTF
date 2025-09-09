/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:36:27 by maralves          #+#    #+#             */
/*   Updated: 2025/09/09 16:35:00 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_case_hex(char c, va_list args)
{
	int			count;
	long long	temp_nbr;

	count = 0;
	if (c == 'x')
		count += ft_putnbr_hex(
				(unsigned long long)va_arg(args, unsigned int), 'l');
	if (c == 'X')
		count += ft_putnbr_hex(
				(unsigned long long)va_arg(args, unsigned int), 'u');
	if (c == 'p')
	{
		temp_nbr = (unsigned long long)va_arg(args, void *);
		if (temp_nbr == 0)
			count += (int)write (1, "(nil)", 5);
		else
		{
			write (1, "0x", 2);
			count += 2;
			count += ft_putnbr_hex(temp_nbr, 'l');
		}
	}
	return (count);
}

int	ft_print_case_dec(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	return (count);
}

int	ft_print_case_char(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		chars_printed;

	va_start(args, str);
	i = 0;
	chars_printed = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%')
				chars_printed += ft_print_case_char(str[i + 1], args);
			if (str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u')
				chars_printed += ft_print_case_dec(str[i + 1], args);
			if (str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == 'p')
				chars_printed += ft_print_case_hex(str[i + 1], args);
			i++;
		}
		else
			chars_printed += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (chars_printed);
}
