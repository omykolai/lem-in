/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:55:42 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/05 15:09:01 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/ft_header.h"

int			g_check_mode;

static void	process_formatted(int fd, const char *format, va_list ap_src)
{
	va_list ap;
	va_list ap_copy;

	va_copy(ap, ap_src);
	va_copy(ap_copy, ap_src);
	init_start(fd);
	while (*format)
	{
		format = buff_put_before_fmt(format);
		if (*format == '%')
			format = render_format(ap, ap_copy, format + 1);
	}
	va_end(ap);
	va_end(ap_copy);
}

void		check_formatted(int fd, const char *format, va_list ap)
{
	g_check_mode = 1;
	process_formatted(fd, format, ap);
}

void		print_formatted(int fd, const char *format, va_list ap)
{
	g_check_mode = 0;
	process_formatted(fd, format, ap);
}
