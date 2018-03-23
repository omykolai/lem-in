/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:52:03 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/17 14:22:32 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../../../includes/ft_header.h"

static char			*get_sign(t_flags *flags, t_fmt_params *p)
{
	if (!p->format)
		exit_message(ERR_MALLOC);
	if (((char*)p->format)[0] == '-')
	{
		p->format = p->format + 1;
		return ("-");
	}
	if (flags->other & F_PLUS)
		return ("+");
	else if (flags->other & F_SPACE)
		return (" ");
	return ("");
}

static void			process_int(t_flags *flags, t_fmt_params *p, char *pref)
{
	if (flags->other & F_PRECISION)
	{
		if (flags->precision > p->fmt_len)
			p->fmt_len = flags->precision;
		p->indent_char = ' ';
	}
	if (ft_strequ(p->format, "0") &&
		(flags->other & F_PRECISION) && flags->precision == 0)
	{
		*((char*)p->format) = '\0';
		p->fmt_len = 0;
		p->fmt_byte_len = 0;
	}
	if ((pref[0] == '0' && !(flags->other & F_POINTER)) &&
		(ft_strequ(p->format, "0") ||
		(ft_tolower(pref[1]) == 'x' && p->fmt_len == 0) ||
					(pref[1] == '\0' && p->fmt_len > p->fmt_byte_len)))
		pref = "";
	p->pref = pref;
}

static intmax_t		get_int(va_list ap, t_flags *flags)
{
	intmax_t res;

	if (flags->other & F_J)
		res = (intmax_t)va_arg(ap, intmax_t);
	else if (flags->other & F_Z)
		res = (intmax_t)va_arg(ap, ssize_t);
	else if (flags->other & F_LL)
		res = (intmax_t)va_arg(ap, long long);
	else if (flags->other & F_L)
		res = (intmax_t)va_arg(ap, long);
	else if (flags->other & F_H)
		res = (short)va_arg(ap, int);
	else if (flags->other & F_HH)
		res = (signed char)va_arg(ap, int);
	else
		res = (intmax_t)va_arg(ap, int);
	return (res);
}

static uintmax_t	get_uint(va_list ap, t_flags *flags)
{
	uintmax_t res;

	if (flags->other & F_J)
		res = (uintmax_t)va_arg(ap, uintmax_t);
	else if (flags->other & F_Z)
		res = (uintmax_t)va_arg(ap, size_t);
	else if (flags->other & F_LL)
		res = (uintmax_t)va_arg(ap, unsigned long long) & ULLONG_MAX;
	else if (flags->other & F_L)
		res = (uintmax_t)va_arg(ap, unsigned long) & ULONG_MAX;
	else if (flags->other & F_H)
		res = (short)va_arg(ap, int) & USHRT_MAX;
	else if (flags->other & F_HH)
		res = (signed char)va_arg(ap, int) & UCHAR_MAX;
	else
		res = (uintmax_t)va_arg(ap, unsigned int) & UINT_MAX;
	return (res);
}

void				num_fmt(va_list ap, t_flags *flags, char *base, char *pref)
{
	t_fmt_params	p;

	init_fmt_params(&p);
	if (!(flags->other & F_SHARP) && !(flags->other & F_POINTER))
		pref = "";
	if (base)
	{
		if (!(p.format = ft_itoa_base(get_uint(ap, flags), base)))
			exit_message(ERR_MALLOC);
	}
	else
	{
		p.format = ft_itoamax(get_int(ap, flags));
		pref = get_sign(flags, &p);
	}
	set_len_params(flags, &p, NULL);
	process_int(flags, &p, pref);
	process_quoted(&p, 0, (flags->other & F_QUOTE));
	process_field_width(&p, flags);
	write_fmt(&p, flags);
	free(p.format - (*pref == '-' ? 1 : 0));
}
