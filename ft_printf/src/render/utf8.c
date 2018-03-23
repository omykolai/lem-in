/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:09:11 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/09 16:22:53 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "../../includes/libft_include.h"

static int	utf8_else(wchar_t c, char *wc)
{
	if (c < 0x10000)
	{
		wc[0] = 224 + c / 4096;
		wc[1] = 128 + c / 64 % 64;
		wc[2] = 128 + c % 64;
		return (3);
	}
	if (c < 0x110000)
	{
		wc[0] = 240 + c / 262144;
		wc[1] = 128 + c / 4096 % 64;
		wc[2] = 128 + c / 64 % 64;
		wc[3] = 128 + c % 64;
		return (4);
	}
	return (0);
}

int			utf8(wchar_t c, char *wc)
{
	if (c < 0)
		return (0);
	if (c < 0x80)
	{
		wc[0] = c;
		return (1);
	}
	if (c < 0x800)
	{
		wc[0] = 192 + c / 64;
		wc[1] = 128 + c % 64;
		return (2);
	}
	if (c - 0xd800u >= 0x800)
		return (utf8_else(c, wc));
	return (0);
}

int			tirm_len(wchar_t *str, int newlen)
{
	int		len;
	int		wlen;
	char	wc[5];

	len = 0;
	wlen = 0;
	while (*str)
	{
		len += utf8(*str, wc);
		if (len > newlen)
			return (wlen);
		++str;
		++wlen;
	}
	return (len);
}
