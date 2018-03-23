/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:13:42 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/04 14:57:57 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_header.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;

	if (fd < 0)
		return (-1);
	va_start(ap, format);
	check_formatted(fd, format, ap);
	if (g_formatted_len != -1)
		print_formatted(fd, format, ap);
	va_end(ap);
	g_b.flush();
	g_formatted_len += g_b.ibuff_utf8 - g_b.buff_utf8 + g_offset_len;
	return (g_formatted_len);
}
