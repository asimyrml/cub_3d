/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayirmili <ayirmili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:43:41 by kgulfida          #+#    #+#             */
/*   Updated: 2025/04/12 18:02:24 by ayirmili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t n)
{
	void	*memory;

	memory = (void *)malloc(count * n);
	if (!memory)
		return (0);
	ft_bzero(memory, (count * n));
	return (memory);
}
