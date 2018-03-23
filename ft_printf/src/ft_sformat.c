/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:13:57 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/06 12:00:23 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_header.h"

static void	set_str(void)
{
	if (g_formatted_len == -1)
		g_formatted_str = NULL;
	if (g_is_wchar)
		g_formatted_str = ft_wstrnew(g_formatted_len);
	else
		g_formatted_str = ft_strnew(g_formatted_len);
}

void		*ft_sformat(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	check_formatted(-1, format, ap);
	g_b.flush();
	set_str();
	if (g_formatted_len != -1)
		print_formatted(-1, format, ap);
	va_end(ap);
	g_b.flush();
	return (g_formatted_str);
}
