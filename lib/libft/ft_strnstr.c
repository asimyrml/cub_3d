/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayirmili <ayirmili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:55:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/04/12 18:03:41 by ayirmili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0' || to_find == str)
		return ((char *)str);
	while (str[j])
	{
		i = 0;
		while (str[j + i] == to_find[i] && (str[i + j]) && (i + j) < n)
		{
			if (to_find[i] == '\0')
				return ((char *)&str[j]);
			i++;
		}
		if (to_find[i] == '\0')
			return ((char *)(str + j));
		j++;
	}
	return (0);
}
