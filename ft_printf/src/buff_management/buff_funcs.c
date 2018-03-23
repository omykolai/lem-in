/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:59:11 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/06 12:00:41 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_header.h"

static int	strlen_ch(const char *str, char c)
{
	int len;

	len = 0;
	while (*str && *str != c)
	{
		++str;
		++len;
	}
	return (len);
}

char		*buff_put_before_fmt(const char *str)
{
	int len1;
	int len2;

	len1 = strlen_ch(str, '%');
	len2 = strlen_ch(str, '{');
	while (len1 > len2)
	{
		buff_put(str, 0, 0, len2);
		str += len2;
		if (!color_dispatcher(&str))
		{
			buff_put(str, 0, 0, 1);
			++str;
		}
		len1 = strlen_ch(str, '%');
		len2 = strlen_ch(str, '{');
	}
	buff_put(str, 0, 0, len1);
	return ((char*)str + len1);
}

void		buff_putchar(int c)
{
	buff_put(NULL, 0, c, 1);
}

void		buff_putstr(void *str, int is_wchar, int len)
{
	buff_put(str, is_wchar, 0, len);
}

void		buff_set(int c, int len)
{
	buff_put(NULL, 0, c, len);
}
