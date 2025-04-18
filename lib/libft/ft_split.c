/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:43:10 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:43:12 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**split_words(char const *s, char c, char **s1, size_t count)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	while (s[start])
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		if (i < count)
			s1[i++] = ft_substr(s, start, (end - start));
		start = end;
	}
	s1[i] = 0;
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	**s1;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	s1 = (char **)malloc(sizeof(char *) * (count + 1));
	if (!s1)
		return (NULL);
	s1 = split_words(s, c, s1, count);
	return (s1);
}
