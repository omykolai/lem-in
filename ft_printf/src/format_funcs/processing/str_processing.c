/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 20:41:17 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/04 22:04:19 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../includes/ft_header.h"

static int	wstrnlen(wchar_t *str, int n)
{
	wchar_t	c[2];
	int		len;

	c[1] = 0;
	len = 0;
	while (*str && n--)
	{
		c[0] = *str++;
		len += u_strlen(c, 1, 0);
	}
	return (len);
}

static void	set_precision(t_flags *flags, t_fmt_params *p)
{
	if ((flags->other & F_PRECISION) && flags->precision < p->fmt_byte_len)
	{
		if (p->is_wchar)
		{
			p->fmt_len = tirm_len(p->format, flags->precision);
			p->fmt_byte_len = wstrnlen(p->format, p->fmt_len);
		}
		else
		{
			p->fmt_len = flags->precision;
			p->fmt_byte_len = flags->precision;
		}
	}
}

static void	set_char_params(t_fmt_params *p, int c)
{
	wchar_t	*fw;
	char	*fc;

	fw = (wchar_t*)p->format;
	fc = (char*)p->format;
	if (p->is_wchar)
	{
		fw[0] = c;
		fw[1] = 0;
	}
	else
	{
		fc[0] = c;
		fc[1] = 0;
	}
	p->fmt_len = 1;
	p->fmt_byte_len = u_strlen(p->format, p->is_wchar, 0);
	if (p->fmt_byte_len == 0)
		p->fmt_byte_len = 1;
}

void		string_fmt(t_flags *flags, t_fmt_params *p)
{
	if (!p->format)
		p->format = (p->is_wchar ? (void*)L"(null)" : (void*)"(null)");
	set_len_params(flags, p, set_precision);
	process_field_width(p, flags);
	write_fmt(p, flags);
}

void		char_fmt(int c, t_flags *flags)
{
	t_fmt_params	p;
	wchar_t			fw[2];
	char			fc[2];

	init_fmt_params(&p);
	p.is_wchar = (flags->other & F_L);
	p.format = p.is_wchar ? (void*)fw : (void*)fc;
	set_char_params(&p, c);
	string_fmt(flags, &p);
}
