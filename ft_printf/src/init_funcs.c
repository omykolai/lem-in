/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:03:12 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/04 14:54:38 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

t_buff	g_b;
int		g_fd;
int		g_is_wchar;
int		g_check_mode;
int		g_offset_len;
int		g_formatted_len;
void	*g_formatted_str;

void	init_start(int fd)
{
	static int	init_buff = 1;

	g_fd = fd;
	g_is_wchar = 0;
	g_b.flush = fd < 0 ? flush_str : flush_fd;
	g_formatted_len = 0;
	if (init_buff)
	{
		g_b.ibuff = g_b.buff;
		g_b.max = g_b.buff + BUFF_SIZE;
		g_b.ibuff_utf8 = g_b.buff_utf8;
		g_b.max_utf8 = g_b.buff_utf8 + BUFF_SIZE;
	}
	g_offset_len = g_b.buff_utf8 - g_b.ibuff_utf8;
	init_buff = 0;
}

void	init_fmt_params(t_fmt_params *params)
{
	params->is_wchar = 0;
	params->indent = -1;
	params->fmt_len = -1;
	params->fmt_byte_len = -1;
	params->indent_char = '\0';
	params->pref = NULL;
}
