/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:25:24 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/06 11:59:40 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft_header.h"

static inline int	get_next_char(wchar_t **wstr, char **cstr, int c)
{
	if (*wstr)
		return (*(*wstr)++);
	if (*cstr)
		return (*(*cstr)++);
	return (c);
}

static void			set_buff_utf8(wchar_t **wstr, char **cstr, int c)
{
	int	ch;
	int	len;

	ch = get_next_char(wstr, cstr, c);
	if (!*wstr || (ch >= 0 && (ch < 127 || (MB_CUR_MAX == 1 && ch < 255))))
		*(g_b.ibuff_utf8)++ = ch;
	else
	{
		len = utf8(ch, g_b.ibuff_utf8);
		if (len == 0 || MB_CUR_MAX < len)
			g_formatted_len = -1;
		else
			g_b.ibuff_utf8 += utf8(ch, g_b.ibuff_utf8);
	}
}

static int			put_len(wchar_t **wstr, char **cstr, int c, int len)
{
	if (g_b.flush == flush_str)
		while (g_b.ibuff < g_b.max && len-- > 0)
			*(g_b.ibuff)++ = get_next_char(wstr, cstr, c);
	else
		while (g_b.ibuff_utf8 < g_b.max_utf8 && len-- > 0)
			set_buff_utf8(wstr, cstr, c);
	return (len);
}

void				buff_put(const void *str, int is_wchar, int c, int len)
{
	wchar_t *wstr;
	char	*cstr;

	if (!g_check_mode || g_b.flush == flush_str)
	{
		wstr = (is_wchar ? (wchar_t*)str : NULL);
		cstr = (is_wchar ? NULL : (char*)str);
		while ((len = put_len(&wstr, &cstr, c, len)) > 0)
			g_b.flush();
	}
}
