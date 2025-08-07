/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:28:38 by maralves          #+#    #+#             */
/*   Updated: 2025/08/04 16:45:18 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;	
	size_t			count;
	size_t			index_direction;

	if (!dest && !src)
		return (NULL);
	index_direction = 1;
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	if (dest > src)
	{
		temp_dest += n - 1;
		temp_src += n - 1;
		index_direction = -1;
	}
	count = 0;
	while (count < n)
	{		
		*temp_dest = *temp_src;
		temp_dest += index_direction;
		temp_src += index_direction;
		count++;
	}
	return (dest);
}
