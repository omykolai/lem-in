/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:22:39 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/05 15:29:36 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

int		ft_sprintf(char *dst, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	check_formatted(1, format, ap);
	g_formatted_str = dst;
	if (g_formatted_len != -1)
		print_formatted(-1, format, ap);
	va_end(ap);
	g_b.flush();
	dst[g_formatted_len] = '\0';
	return (g_formatted_len);
}
