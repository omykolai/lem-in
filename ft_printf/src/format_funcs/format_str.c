/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:11:47 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/04 18:57:06 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include "../../includes/ft_header.h"

void	s_fmt(va_list ap, t_flags *flags)
{
	t_fmt_params	p;

	if ((flags->other & F_L))
		ls_fmt(ap, flags);
	else
	{
		init_fmt_params(&p);
		p.format = va_arg(ap, char *);
		string_fmt(flags, &p);
	}
}

void	ls_fmt(va_list ap, t_flags *flags)
{
	t_fmt_params	p;

	init_fmt_params(&p);
	p.is_wchar = 1;
	p.format = va_arg(ap, wchar_t *);
	string_fmt(flags, &p);
}

void	c_fmt(va_list ap, t_flags *flags)
{
	char_fmt(va_arg(ap, int), flags);
}

void	lc_fmt(va_list ap, t_flags *flags)
{
	flags->other |= F_L;
	c_fmt(ap, flags);
}

void	percent_fmt(va_list ap, t_flags *flags)
{
	ap = NULL;
	char_fmt('%', flags);
}
