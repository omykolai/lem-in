/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:51:36 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/14 17:51:43 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	check_str(const char *s1, const char *s2, size_t len)
{
	while (*s1 == *s2 && *s1 && len)
	{
		++s1;
		++s2;
		--len;
	}
	if (*s1)
		return (0);
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char*)haystack);
	while (*haystack && len)
	{
		if (check_str(needle, haystack, len))
			return ((char*)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
