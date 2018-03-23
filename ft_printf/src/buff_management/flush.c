/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:15:32 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/05 15:20:38 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/ft_header.h"

void		flush_fd(void)
{
	int	len;

	if ((len = g_b.ibuff_utf8 - g_b.buff_utf8) > 0)
	{
		if (!g_check_mode && g_formatted_len >= 0)
			write(g_fd, g_b.buff_utf8, len);
		if (g_formatted_len >= 0)
			g_formatted_len += len;
		g_b.ibuff_utf8 = g_b.buff_utf8;
	}
}

void		flush_str(void)
{
	int		len;
	char	*istr;

	if (g_formatted_len >= 0)
	{
		if ((len = g_b.ibuff - g_b.buff) > 0)
		{
			istr = g_formatted_str + g_formatted_len;
			if (!g_check_mode && g_formatted_len >= 0)
				u_strncpy(istr, g_b.buff, len, g_is_wchar);
			if (g_formatted_len >= 0)
				g_formatted_len += len;
			g_b.ibuff = g_b.buff;
		}
	}
}

void		ft_fflush(void)
{
	g_b.flush();
}
