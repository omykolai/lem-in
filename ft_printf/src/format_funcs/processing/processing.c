/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:36:07 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/04 22:01:28 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../includes/ft_header.h"

static int	write_quoted(char *str, int len, int write_)
{
	int		quote_count;

	quote_count = 0;
	while (len > 0)
	{
		if (write_)
		{
			buff_putchar(',');
			buff_putstr(str, 0, 3);
		}
		len -= 3;
		str += 3;
		++quote_count;
	}
	return (quote_count);
}

void		process_quoted(t_fmt_params *p, int write_, int format_quote)
{
	int		len;
	int		mod3;
	int		q_count;
	int		off;

	q_count = 0;
	len = ft_strlen(p->format);
	if (format_quote)
	{
		if ((mod3 = len % 3) == 0 && len > 0 && write_)
			buff_putstr(p->format, 0, 3);
		else if (len > 0 && write_)
			buff_putstr(p->format, 0, mod3);
		off = (mod3 == 0 ? 3 : mod3);
		q_count = write_quoted(p->format + off, len - off, write_);
		p->fmt_byte_len = len + q_count;
	}
	else if (write_)
		buff_putstr(p->format, p->is_wchar, p->fmt_len);
}

void		set_len_params(t_flags *flags, t_fmt_params *p,
	void (*set_precision)(t_flags*, t_fmt_params*))
{
	if (p->fmt_byte_len == -1)
		p->fmt_byte_len = u_strlen(p->format, p->is_wchar, 0);
	if (p->fmt_len == -1)
	{
		p->fmt_len = u_strlen(p->format, p->is_wchar, 1);
		if (set_precision != NULL)
			set_precision(flags, p);
	}
}

void		process_field_width(t_fmt_params *p, t_flags *flags)
{
	int		len;

	len = (p->fmt_len > p->fmt_byte_len ? p->fmt_len : p->fmt_byte_len);
	if (p->pref)
		len += ft_strlen(p->pref);
	if (flags->other & F_WIDTH)
	{
		if (len < flags->width)
		{
			p->indent = flags->width - len;
			if (!(flags->other & F_MINUS) && (flags->other & F_ZERO) &&
				p->indent_char != ' ')
				p->indent_char = '0';
			else
				p->indent_char = ' ';
		}
		else
			flags->other &= ~F_WIDTH;
	}
}
