/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:19:06 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/09 16:23:01 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdarg.h>
# include <wchar.h>
# include "../includes/libft_include.h"
# include "ft_colors.h"
# define BUFF_SIZE 4096

typedef enum		e_error
{
	ERR_FORMAT = 1,
	ERR_MALLOC = 2,
}					t_error;

typedef enum		e_flags
{
	F_NONE = 0,
	F_SHARP = 1,
	F_ZERO = 2,
	F_SPACE = 4,
	F_MINUS = 8,
	F_PLUS = 16,
	F_WIDTH = 32,
	F_PRECISION = 64,
	F_HH = 128,
	F_H = 256,
	F_L = 512,
	F_LL = 1024,
	F_J = 2048,
	F_Z = 4096,
	F_UPPER_L = 8192,
	F_STAR = 16384,
	F_DOLLAR = 32768,
	F_QUOTE = 65536,
	F_POINTER = 131072,
	F_ALL = -1
}					t_flags_enum;

typedef struct		s_flags
{
	int				width;
	int				precision;
	int				argnum;
	t_flags_enum	other;
}					t_flags;

typedef struct		s_fmt_func
{
	void			(*func)(va_list ap, t_flags *flags);
	char			fmt;
}					t_fmt_func;

typedef struct		s_buff
{
	wchar_t			buff[BUFF_SIZE];
	char			buff_utf8[BUFF_SIZE + 4];
	wchar_t			*ibuff;
	char			*ibuff_utf8;
	wchar_t			*max;
	char			*max_utf8;
	void			(*flush)(void);
}					t_buff;

typedef struct		s_fmt_params
{
	void			*format;
	int				is_wchar;
	int				fmt_len;
	int				fmt_byte_len;
	int				indent;
	char			indent_char;
	char			*pref;
}					t_fmt_params;

extern t_buff		g_b;
extern int			g_fd;
extern int			g_is_wchar;
extern int			g_check_mode;
extern void			*g_formatted_str;
extern int			g_formatted_len;
extern int			g_offset_len;

void				init_start(int fd);
void				init_fmt_params(t_fmt_params *params);
void				exit_message(t_error e);

void				check_formatted(int fd, const char *format, va_list ap);
void				print_formatted(int fd, const char *format, va_list ap);
int					format_dispatcher(va_list ap, char fmt, t_flags *flags);
int					flag_dispatcher(const char **fmt, t_flags *flags);
int					color_dispatcher(const char **fmt);

int					space_flag(const char **fmt, t_flags *flags);
int					minus_flag(const char **fmt, t_flags *flags);
int					plus_flag(const char **fmt, t_flags *flags);
int					width_flag(const char **fmt, t_flags *flags);
int					precision_flag(const char **fmt, t_flags *flags);
int					h_flag(const char **fmt, t_flags *flags);
int					l_flag(const char **fmt, t_flags *flags);
int					j_flag(const char **fmt, t_flags *flags);
int					z_flag(const char **fmt, t_flags *flags);
int					upper_l_flag(const char **fmt, t_flags *flags);
int					sharp_flag(const char **fmt, t_flags *flags);
int					zero_flag(const char **fmt, t_flags *flags);
int					star_flag(const char **fmt, t_flags *flags);
void				star_render(va_list ap, const char *fmt, t_flags *flags);
int					dollar_flag(const char **fmt, t_flags *flags);
int					quote_flag(const char **fmt, t_flags *flags);

void				s_fmt(va_list ap, t_flags *flags);
void				ls_fmt(va_list ap, t_flags *flags);
void				c_fmt(va_list ap, t_flags *flags);
void				lc_fmt(va_list ap, t_flags *flags);
void				percent_fmt(va_list ap, t_flags *flags);
void				d_fmt(va_list ap, t_flags *flags);
void				u_fmt(va_list ap, t_flags *flags);
void				ld_fmt(va_list ap, t_flags *flags);
void				lu_fmt(va_list ap, t_flags *flags);
void				x_fmt(va_list ap, t_flags *flags);
void				lx_fmt(va_list ap, t_flags *flags);
void				o_fmt(va_list ap, t_flags *flags);
void				lo_fmt(va_list ap, t_flags *flags);
void				p_fmt(va_list ap, t_flags *flags);
void				n_fmt(va_list ap, t_flags *flags);
void				b_fmt(va_list ap, t_flags *flags);
void				write_fmt(t_fmt_params *p, t_flags *flags);

void				process_quoted(t_fmt_params *p, int write_,
	int format_quote);
void				set_len_params(t_flags *flags, t_fmt_params *p,
	void (*set_precision)(t_flags*, t_fmt_params*));
void				process_field_width(t_fmt_params *p, t_flags *flags);
void				string_fmt(t_flags *flags, t_fmt_params *p);
void				char_fmt(int c, t_flags *flags);
void				num_fmt(va_list ap, t_flags *flags, char *base, char *pref);

const char			*render_format(va_list ap, va_list ap_cp, const char *fmt);
int					utf8(wchar_t c, char wc[5]);
size_t				tirm_len(wchar_t *str, int newlen);

char				*buff_put_before_fmt(const char *str);
void				buff_put(const void *str, int is_wchar, int c, int len);
void				buff_putchar(int c);
void				buff_putstr(void *str, int is_wchar, int len);
void				buff_set(int c, int len);

void				flush_fd(void);
void				flush_str(void);

size_t				u_strlen(void *str, int is_wchar, int by_wchar);
void				*u_strncpy(void *dst, const wchar_t *src, size_t len,
	int is_wchar);

#endif
