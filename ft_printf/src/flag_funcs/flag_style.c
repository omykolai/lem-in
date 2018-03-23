/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_style.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:38:44 by omykolai          #+#    #+#             */
/*   Updated: 2018/01/29 17:01:20 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_header.h"

int		sharp_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == '#')
	{
		flags->other |= F_SHARP;
		++*fmt;
		return (1);
	}
	return (0);
}

int		zero_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == '0')
	{
		flags->other |= F_ZERO;
		++*fmt;
		return (1);
	}
	return (0);
}
