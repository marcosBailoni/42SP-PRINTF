/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:58:24 by vboxuser          #+#    #+#             */
/*   Updated: 2025/09/05 19:59:51 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	char	temp;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	temp = n % 10 + '0';
	count += ft_putchar(temp);
	return (count);
}
