/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:33:02 by vboxuser          #+#    #+#             */
/*   Updated: 2025/09/06 03:32:13 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(unsigned long long nbr, char letter_case)
{
	char	*hex;
	int		count;

	if (letter_case == 'u')
		hex = "0123456789ABCDEF";
	if (letter_case == 'l')
		hex = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_putnbr_hex(nbr / 16, letter_case);
	count += ft_putchar(hex[nbr % 16]);
	return (count);
}
