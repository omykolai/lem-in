/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:29:34 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/05 14:53:05 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

# define FG_BLACK "\x1b[30m"
# define FG_RED "\x1b[31m"
# define FG_GREEN "\x1b[32m"
# define FG_YELLOW "\x1b[33m"
# define FG_BLUE "\x1b[34m"
# define FG_MAGENTA "\x1b[35m"
# define FG_CYAN "\x1b[36m"
# define FG_WHITE "\x1b[37m"

# define FG_BRIGHT_BLACK "\x1b[90m"
# define FG_BRIGHT_RED "\x1b[91m"
# define FG_BRIGHT_GREEN "\x1b[92m"
# define FG_BRIGHT_YELLOW "\x1b[93m"
# define FG_BRIGHT_BLUE "\x1b[94m"
# define FG_BRIGHT_MAGENTA "\x1b[95m"
# define FG_BRIGHT_CYAN "\x1b[96m"
# define FG_BRIGHT_WHITE "\x1b[97m"

# define BG_BLACK "\x1b[40m"
# define BG_RED "\x1b[41m"
# define BG_GREEN "\x1b[42m"
# define BG_YELLOW "\x1b[43m"
# define BG_BLUE "\x1b[44m"
# define BG_MAGENTA "\x1b[45m"
# define BG_CYAN "\x1b[46m"
# define BG_WHITE "\x1b[47m"

# define BG_BRIGHT_BLACK "\x1b[100m"
# define BG_BRIGHT_RED "\x1b[101m"
# define BG_BRIGHT_GREEN "\x1b[102m"
# define BG_BRIGHT_YELLOW "\x1b[103m"
# define BG_BRIGHT_BLUE "\x1b[104m"
# define BG_BRIGHT_MAGENTA "\x1b[105m"
# define BG_BRIGHT_CYAN "\x1b[106m"
# define BG_BRIGHT_WHITE "\x1b[107m"

# define COLOR_RESET   "\x1b[0m"

typedef struct		s_color
{
	char			*name;
	char			*code;
	int				len;
}					t_color;

#endif
