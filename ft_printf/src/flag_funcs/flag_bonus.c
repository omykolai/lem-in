/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:20:39 by omykolai          #+#    #+#             */
/*   Updated: 2018/01/29 17:01:04 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_header.h"

int		star_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == '*')
	{
		flags->other |= F_STAR;
		++*fmt;
		return (1);
	}
	return (0);
}

void	star_render(va_list ap, const char *fmt, t_flags *flags)
{
	if (*(fmt - 2) == '.')
	{
		flags->precision = va_arg(ap, int);
		if (flags->precision < 0)
			flags->other &= ~F_PRECISION;
	}
	else
	{
		flags->other |= F_WIDTH;
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->other |= F_MINUS;
			flags->width = -flags->width;
		}
	}
}

int		dollar_flag(const char **fmt, t_flags *flags)
{
	const char	*fmt_tmp;
	int			argnum;

	fmt_tmp = *fmt;
	argnum = ft_atoi(fmt_tmp);
	while (ft_isdigit(*fmt_tmp))
		++fmt_tmp;
	if (*fmt_tmp == '$')
	{
		flags->other |= F_DOLLAR;
		flags->argnum = argnum;
		if (flags->argnum < 0)
		{
			flags->other |= F_MINUS;
			flags->argnum = -flags->argnum;
		}
		*fmt = fmt_tmp + 1;
		return (1);
	}
	return (0);
}

int		quote_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == '\'')
	{
		flags->other |= F_QUOTE;
		++*fmt;
		return (1);
	}
	return (0);
}
