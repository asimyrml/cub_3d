/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:42:43 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:42:45 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;

	dest1 = (unsigned char *)dest;
	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	else if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else
	{
		while (n--)
		{
			*(unsigned char *)dest = *(unsigned char *)src;
			dest++;
			src++;
		}
	}
	return (dest1);
}
