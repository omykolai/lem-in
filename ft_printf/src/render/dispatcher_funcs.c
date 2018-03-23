/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:26:25 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/05 15:03:06 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft_header.h"

static const int		g_fmt_count = 17;
static const int		g_flag_count = 14;
static const int		g_color_count = 33;
static const t_fmt_func	g_fmt_funcs[] =
{
	{ .func = s_fmt, .fmt = 's' },
	{ .func = ls_fmt, .fmt = 'S' },
	{ .func = c_fmt, .fmt = 'c' },
	{ .func = lc_fmt, .fmt = 'C' },
	{ .func = percent_fmt, .fmt = '%' },
	{ .func = d_fmt, .fmt = 'd' },
	{ .func = ld_fmt, .fmt = 'D' },
	{ .func = d_fmt, .fmt = 'i' },
	{ .func = u_fmt, .fmt = 'u' },
	{ .func = lu_fmt, .fmt = 'U' },
	{ .func = x_fmt, .fmt = 'x' },
	{ .func = lx_fmt, .fmt = 'X' },
	{ .func = o_fmt, .fmt = 'o' },
	{ .func = lo_fmt, .fmt = 'O' },
	{ .func = p_fmt, .fmt = 'p' },
	{ .func = n_fmt, .fmt = 'n' },
	{ .func = b_fmt, .fmt = 'b' }
};
static int				(*const g_flag_funcs[])(const char **, t_flags *) =
{
	space_flag,
	minus_flag,
	plus_flag,
	width_flag,
	precision_flag,
	sharp_flag,
	zero_flag,
	h_flag,
	l_flag,
	j_flag,
	z_flag,
	upper_l_flag,
	star_flag,
	quote_flag
};
static const t_color			g_colors[] =
{
	{ .name = "fg_black", .code = FG_BLACK, .len = 8 },
	{ .name = "fg_red", .code = FG_RED, .len = 6 },
	{ .name = "fg_green", .code = FG_GREEN, .len = 8 },
	{ .name = "fg_yellow", .code = FG_YELLOW, .len = 9 },
	{ .name = "fg_blue", .code = FG_BLUE, .len = 7 },
	{ .name = "fg_magneta", .code = FG_MAGENTA, .len = 10 },
	{ .name = "fg_cyan", .code = FG_CYAN, .len = 7 },
	{ .name = "fg_white", .code = FG_WHITE, .len = 8 },

	{ .name = "fg_bblack", .code = FG_BRIGHT_BLACK, .len = 9 },
	{ .name = "fg_bred", .code = FG_BRIGHT_RED, .len = 7 },
	{ .name = "fg_bgreen", .code = FG_BRIGHT_GREEN, .len = 9 },
	{ .name = "fg_byellow", .code = FG_BRIGHT_YELLOW, .len = 10 },
	{ .name = "fg_bblue", .code = FG_BRIGHT_BLUE, .len = 8 },
	{ .name = "fg_bmagneta", .code = FG_BRIGHT_MAGENTA, .len = 11 },
	{ .name = "fg_bcyan", .code = FG_BRIGHT_CYAN, .len = 8 },
	{ .name = "fg_bwhite", .code = FG_BRIGHT_WHITE, .len = 9 },

	{ .name = "bg_black", .code = BG_BLACK, .len = 8 },
	{ .name = "bg_red", .code = BG_RED, .len = 6 },
	{ .name = "bg_green", .code = BG_GREEN, .len = 8 },
	{ .name = "bg_yellow", .code = BG_YELLOW, .len = 9 },
	{ .name = "bg_blue", .code = BG_BLUE, .len = 7 },
	{ .name = "bg_magneta", .code = BG_MAGENTA, .len = 10 },
	{ .name = "bg_cyan", .code = BG_CYAN, .len = 7 },
	{ .name = "bg_white", .code = BG_WHITE, .len = 8 },

	{ .name = "bg_bblack", .code = BG_BRIGHT_BLACK, .len = 9 },
	{ .name = "bg_bred", .code = BG_BRIGHT_RED, .len = 7 },
	{ .name = "bg_bgreen", .code = BG_BRIGHT_GREEN, .len = 9 },
	{ .name = "bg_byellow", .code = BG_BRIGHT_YELLOW, .len = 10 },
	{ .name = "bg_bblue", .code = BG_BRIGHT_BLUE, .len = 8 },
	{ .name = "bg_bmagneta", .code = BG_BRIGHT_MAGENTA, .len = 11 },
	{ .name = "bg_bcyan", .code = BG_BRIGHT_CYAN, .len = 8 },
	{ .name = "bg_bwhite", .code = BG_BRIGHT_WHITE, .len = 9 },
	{ .name = "eoc", .code = COLOR_RESET, .len = 3 }
};

static int	check_wchar(char fmt, t_flags *flags)
{
	if (g_is_wchar == 1)
		return (1);
	if (fmt == 'S' || fmt == 'C' ||
		((fmt == 's' || fmt == 'c') &&
		(flags->other & F_L)))
		return (1);
	return (0);
}

int			format_dispatcher(va_list ap, char fmt, t_flags *flags)
{
	int			i;

	i = -1;
	while (++i < g_fmt_count)
		if (g_fmt_funcs[i].fmt == fmt)
		{
			g_is_wchar = check_wchar(fmt, flags);
			g_fmt_funcs[i].func(ap, flags);
			return (1);
		}
	return (0);
}

int			flag_dispatcher(const char **fmt, t_flags *flags)
{
	int		i;

	i = -1;
	while (++i < g_flag_count)
		if (g_flag_funcs[i](fmt, flags))
			return (1);
	return (0);
}

int			color_dispatcher(const char **fmt)
{
	int			i;

	if (**fmt == '{')
	{
		i = -1;
		while (++i < g_color_count)
			if (ft_strnequ(g_colors[i].name, *fmt + 1, g_colors[i].len) &&
				*(*fmt + 1 + g_colors[i].len) == '}')
			{
				buff_putstr(g_colors[i].code, 0, ft_strlen(g_colors[i].code));
				*fmt += 2 + g_colors[i].len;
				return (1);
			}
	}
	return (0);
}
