/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:49:16 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/06 11:48:38 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_header.h"

void	n_fmt(va_list ap, t_flags *flags)
{
	int *n;

	flags = NULL;
	if ((n = va_arg(ap, int *)))
	{
		*n = g_formatted_len;
		if (*n >= 0)
		{
			if (g_b.flush == flush_fd)
				*n += g_b.ibuff_utf8 - g_b.buff_utf8;
			else
				*n += g_b.ibuff - g_b.buff;
		}
	}
}

void	b_fmt(va_list ap, t_flags *flags)
{
	flags->other |= F_J;
	num_fmt(ap, flags, "01", "");
}
