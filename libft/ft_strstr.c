/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:29:47 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/14 16:29:50 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	check_str(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	if (*s1)
		return (0);
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		if (check_str(needle, haystack))
			return ((char*)haystack);
		++haystack;
	}
	return (NULL);
}
