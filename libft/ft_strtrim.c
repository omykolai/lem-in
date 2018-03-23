/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:54:51 by omykolai          #+#    #+#             */
/*   Updated: 2017/12/26 16:56:09 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	trim_len(char const *s)
{
	size_t len;

	len = 0;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		++s;
	while (*s)
	{
		++len;
		++s;
	}
	--s;
	while (len && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		--len;
		--s;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*trim;
	char	*itrim;
	size_t	len;

	if (!s || !(trim = (char*)malloc(sizeof(char) *
		((len = trim_len(s)) + 1))))
		return (NULL);
	itrim = trim;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		++s;
	while (len--)
	{
		*itrim = *s;
		++s;
		++itrim;
	}
	*itrim = '\0';
	return (trim);
}
