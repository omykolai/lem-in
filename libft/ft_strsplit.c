/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:40:39 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/17 19:41:59 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	strs_len(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
			++len;
		while (*s && *s != c)
			++s;
	}
	return (len);
}

static size_t	s_len(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s != c)
	{
		++len;
		++s;
	}
	return (len);
}

static char		*get_next_str(char const *s, char c, size_t *i)
{
	char *result;
	char *ires;

	if (!(result = (char*)malloc(sizeof(char) * (s_len(s, c) + 1))))
		return (NULL);
	ires = result;
	while (s[*i] && s[*i] != c)
	{
		*ires = s[*i];
		++ires;
		++*i;
	}
	*ires = 0;
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**strs;
	char	**istrs;
	size_t	i;

	if (!s || !(strs = (char**)malloc(sizeof(char*) * (strs_len(s, c) + 1))))
		return (NULL);
	istrs = strs;
	i = 0;
	while (1)
	{
		while (s[i] && s[i] == c)
			++i;
		if (!s[i])
			break ;
		if (!(*istrs = get_next_str(s, c, &i)))
			return (NULL);
		++istrs;
	}
	*(istrs) = NULL;
	return (strs);
}
