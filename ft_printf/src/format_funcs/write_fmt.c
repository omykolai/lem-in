/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:43:17 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/05 14:17:56 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_header.h"

typedef void	(*t_putfunc)(t_fmt_params*, t_flags*);

static void	put_indent(t_fmt_params *p, t_flags *flags)
{
	if (flags->other & F_WIDTH)
		buff_set(p->indent_char, p->indent);
}

static void	put_arg(t_fmt_params *p, t_flags *flags)
{
	if (p->fmt_len > p->fmt_byte_len)
		while (p->fmt_len > p->fmt_byte_len)
		{
			buff_putchar('0');
			--p->fmt_len;
		}
	process_quoted(p, 1, (flags->other & F_QUOTE) && p->pref != NULL);
}

static void	put_pref(t_fmt_params *p, t_flags *flags)
{
	int len;

	if (p->pref)
	{
		len = ft_strlen(p->pref);
		buff_putstr(p->pref, 0, len);
	}
	flags = NULL;
}

static void	order_funcs(t_fmt_params *p, t_flags *flags, t_putfunc putfuncs[5])
{
	putfuncs[3] = put_arg;
	if (flags->other & F_MINUS)
		putfuncs[4] = put_indent;
	else
	{
		if (p->indent_char == '0')
			putfuncs[0] = put_pref;
		putfuncs[1] = put_indent;
	}
	if (!putfuncs[0])
		putfuncs[2] = put_pref;
}

void		write_fmt(t_fmt_params *p, t_flags *flags)
{
	t_putfunc	putfuncs[5];
	int			i;

	ft_memset(putfuncs, 0, 5 * sizeof(t_putfunc));
	order_funcs(p, flags, putfuncs);
	i = -1;
	while (++i < 5)
		if (putfuncs[i])
			putfuncs[i](p, flags);
}
