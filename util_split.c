/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:28:20 by pruenrua          #+#    #+#             */
/*   Updated: 2023/07/31 13:35:49 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	count_on_me(char const *s, char c)
{
	int	word;
	int	skip;

	skip = 0;
	word = 0;
	while (*s)
	{
		if (*s == c && skip == 1)
			skip = 0;
		if (*s != c && skip == 0)
		{
			word++;
			skip = 1;
		}
		s++;
	}
	return (word);
}

static size_t	how_long(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			return (count);
		count++;
		s++;
	}
	return (count);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subbstr;
	size_t	i;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s + start);
	subbstr = malloc(len + 1);
	if (!subbstr)
		return (0);
	i = 0;
	while (len - i && start + i < ft_strlen(s))
	{
		*(subbstr + i) = *(s + (start + i));
		i++;
	}
	*(subbstr + i) = '\0';
	return (subbstr);
}

char	**ft_split(char const *s, char c)
{
	char	**resplit;
	size_t	i;
	size_t	big_i;

	if (!s)
		return (0);
	i = 0;
	big_i = 0;
	resplit = (char **)malloc((sizeof(char *)) * (count_on_me(s, c) + 1));
	if (!resplit)
		return (0);
	while (s[i] && i <= ft_strlen(s))
	{
		if (s[i] != c)
		{
			resplit[big_i] = ft_substr(s, i, how_long(&s[i], c));
			i = i + how_long(&s[i], c);
			big_i++;
		}
		if (s[i] == c)
			i++;
	}
	resplit[big_i] = NULL;
	return (resplit);
}