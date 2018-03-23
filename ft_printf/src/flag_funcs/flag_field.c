/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:16:37 by omykolai          #+#    #+#             */
/*   Updated: 2018/01/29 17:01:10 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_header.h"

int		space_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == ' ')
	{
		flags->other |= F_SPACE;
		++*fmt;
		return (1);
	}
	return (0);
}

int		minus_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == '-')
	{
		flags->other |= F_MINUS;
		++*fmt;
		return (1);
	}
	return (0);
}

int		plus_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == '+')
	{
		flags->other |= F_PLUS;
		++*fmt;
		return (1);
	}
	return (0);
}

int		width_flag(const char **fmt, t_flags *flags)
{
	if (ft_isdigit(**fmt) && **fmt != '0')
	{
		if (dollar_flag(fmt, flags))
			return (1);
		flags->other |= F_WIDTH;
		flags->width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			++*fmt;
		return (1);
	}
	return (0);
}

int		precision_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == '.')
	{
		++*fmt;
		flags->other |= F_PRECISION;
		if (ft_isdigit(**fmt))
			flags->precision = ft_atoi(*fmt);
		else
			flags->precision = 0;
		while (ft_isdigit(**fmt))
			++*fmt;
		return (1);
	}
	return (0);
}
