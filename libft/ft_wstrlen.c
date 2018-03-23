/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:14:52 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/09 17:37:31 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <wchar.h>

static size_t	utf8_size(wchar_t c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c - 0xd800u >= 0x800)
	{
		if (c < 0x10000)
			return (3);
		else if (c < 0x110000)
			return (4);
	}
	return (1);
}

size_t			ft_wstrlen(const wchar_t *str, int is_byte_len)
{
	size_t len;

	len = 0;
	while (*str)
	{
		len += (is_byte_len ? utf8_size(*str) : 1);
		++str;
	}
	return (len);
}
