/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:44:58 by omykolai          #+#    #+#             */
/*   Updated: 2018/01/29 17:01:13 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_header.h"

int		h_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == 'h')
	{
		++*fmt;
		if (**fmt == 'h')
		{
			++*fmt;
			flags->other |= F_HH;
		}
		else
			flags->other |= F_H;
		return (1);
	}
	return (0);
}

int		l_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == 'l')
	{
		++*fmt;
		if (**fmt == 'l')
		{
			++*fmt;
			flags->other |= F_LL;
		}
		else
			flags->other |= F_L;
		return (1);
	}
	return (0);
}

int		j_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == 'j')
	{
		flags->other |= F_J;
		++*fmt;
		return (1);
	}
	return (0);
}

int		z_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == 'z')
	{
		flags->other |= F_Z;
		++*fmt;
		return (1);
	}
	return (0);
}

int		upper_l_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == 'L')
	{
		flags->other |= F_UPPER_L;
		++*fmt;
		return (1);
	}
	return (0);
}
