/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:36:27 by maralves          #+#    #+#             */
/*   Updated: 2025/08/25 17:42:59 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hex(int nbr, char letter_case)
{
	char	*hex;
	int		temp;

	if (letter_case == 'u')
		hex = "0123456789ABCDEF";
	if (letter_case == 'l')
		hex = "0123456789abcdef";
	if (nbr > 16)
		ft_putnbr_hex(nbr / 16, letter_case);
	temp = nbr % 16;
	ft_putchar_fd(hex[temp], 1);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	char	*new;
	int		i;
	
	new = str;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			if (str[i + 1] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			if (str[i + 1] == 'p');
			if (str[i + 1] == 'd');
			if (str[i + 1] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			if (str[i + 1] == 'u');
			if (str[i + 1] == 'x')
				ft_putnbr_hex(va_arg(args, int), 'l');
			if (str[i + 1] == 'X')
				ft_putnbr_hex(va_arg(args, int), 'u');
			if (str[i + 1] == '%')
				ft_putchar_fd('%', 1);			
			i++;
		}
		else
			ft_putchar_fd(str[i]);
		i++;
	}
}