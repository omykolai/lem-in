/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 09:02:26 by omykolai          #+#    #+#             */
/*   Updated: 2017/09/26 09:05:09 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	pre_return(const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
		++i;
	return (i + size);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && ++j < dstsize)
		++i;
	if (i != j)
		return (pre_return(src, dstsize));
	while (*src != '\0' && ++j < dstsize)
	{
		dst[i] = *src;
		++i;
		++src;
	}
	dst[i] = '\0';
	while (*src != '\0')
	{
		++src;
		++i;
	}
	return (i);
}
