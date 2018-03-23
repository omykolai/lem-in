/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:25:05 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/07 17:05:55 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../includes/ft_header.h"

static void	set_ap(va_list ap, va_list ap_copy, t_flags *flags)
{
	va_end(ap);
	va_copy(ap, ap_copy);
	va_end(ap_copy);
	va_copy(ap_copy, ap);
	while (--flags->argnum)
		va_arg(ap, void *);
	flags->other &= ~F_DOLLAR;
}

const char	*render_format(va_list ap, va_list ap_cp, const char *fmt)
{
	t_flags	flags;

	flags.other = F_NONE;
	while (*fmt)
	{
		if (flags.other & F_DOLLAR)
			set_ap(ap, ap_cp, &flags);
		if (format_dispatcher(ap, *fmt, &flags))
			return (fmt + 1);
		if (!flag_dispatcher(&fmt, &flags))
			break ;
		if (flags.other & F_STAR)
		{
			star_render(ap, fmt, &flags);
			flags.other &= ~F_STAR;
		}
	}
	exit_message(ERR_FORMAT);
	return (fmt);
}
