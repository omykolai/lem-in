/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:47:59 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/01 17:36:05 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft_header.h"

void		d_fmt(va_list ap, t_flags *flags)
{
	num_fmt(ap, flags, NULL, "");
}

void		u_fmt(va_list ap, t_flags *flags)
{
	num_fmt(ap, flags, "0123456789", "");
}

void		ld_fmt(va_list ap, t_flags *flags)
{
	flags->other |= F_J;
	num_fmt(ap, flags, NULL, "");
}

void		lu_fmt(va_list ap, t_flags *flags)
{
	flags->other |= F_J;
	num_fmt(ap, flags, "0123456789", "");
}
