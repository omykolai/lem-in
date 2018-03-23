/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:53:26 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/05 14:19:05 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft_header.h"

void	x_fmt(va_list ap, t_flags *flags)
{
	flags->other &= ~F_QUOTE;
	num_fmt(ap, flags, "0123456789abcdef",
		(flags->other & F_SHARP) ? "0x" : "");
}

void	lx_fmt(va_list ap, t_flags *flags)
{
	flags->other &= ~F_QUOTE;
	num_fmt(ap, flags, "0123456789ABCDEF",
		(flags->other & F_SHARP) ? "0X" : "");
}

void	o_fmt(va_list ap, t_flags *flags)
{
	num_fmt(ap, flags, "01234567",
		(flags->other & F_SHARP) ? "0" : "");
}

void	lo_fmt(va_list ap, t_flags *flags)
{
	flags->other |= F_J;
	num_fmt(ap, flags, "01234567",
		(flags->other & F_SHARP) ? "0" : "");
}

void	p_fmt(va_list ap, t_flags *flags)
{
	flags->other &= ~F_QUOTE;
	flags->other |= F_J;
	flags->other |= F_POINTER;
	num_fmt(ap, flags, "0123456789abcdef", "0x");
}
