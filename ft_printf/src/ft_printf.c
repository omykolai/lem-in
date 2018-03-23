/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:08:57 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/04 19:23:27 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_header.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	g_fd = 1;
	check_formatted(1, format, ap);
	if (g_formatted_len != -1)
		print_formatted(1, format, ap);
	va_end(ap);
	g_b.flush();
	if (g_formatted_len >= 0)
		g_formatted_len += g_b.ibuff_utf8 - g_b.buff_utf8 + g_offset_len;
	return (g_formatted_len);
}
