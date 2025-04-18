/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:44:04 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:44:06 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (ft_strdup(s1));
	while (s1[i] && ft_check(*(s1 + i), set))
		i++;
	len = ft_strlen(s1);
	if (i >= len)
		return (ft_strdup(""));
	else
	{
		while (len != 0 && ft_check(*(s1 + (len - 1)), set))
			len--;
		str = ft_substr(s1, i, len - i);
	}
	return (str);
}
