/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:23:20 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:48 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "../../includes/read.h"
#include "../../ft_printf/includes/ft_printf.h"

static inline void	exec_cmd(t_room *r)
{
	if (g_rd_params.cmd == CMD_START)
	{
		if (g_farm.start)
			exit_error("start command used twice");
		g_farm.start = r;
	}
	else if (g_rd_params.cmd == CMD_END)
	{
		if (g_farm.end)
			exit_error("end command used twice");
		g_farm.end = r;
	}
}

bool				check_int(char *str, int len)
{
	intmax_t	n;

	if (!len || len > 11)
		return (false);
	while (len--)
	{
		if (!ft_isdigit(str[len]))
			if (str[len] != '-' || len != 0)
				return (false);
	}
	n = ft_atoimax(str);
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	return (true);
}

static bool			check_coord_pos(const char *str, char *x_pos, char *y_pos)
{
	if (x_pos > str
		&& y_pos - x_pos > 1
		&& *(y_pos + 1) != '\0')
	{
		if (!check_int(x_pos + 1, y_pos - x_pos - 1))
			return (false);
		if (!check_int(y_pos + 1, ft_strlen(y_pos + 1)))
			return (false);
		return (true);
	}
	return (false);
}

static bool			set_coord_pos(char *str, char **x_pos, char **y_pos)
{
	char *istr;

	*x_pos = NULL;
	*y_pos = NULL;
	istr = str;
	while (*istr)
	{
		if (*istr == ' ')
		{
			*x_pos = *y_pos;
			*y_pos = istr;
		}
		++istr;
	}
	if (check_coord_pos(str, *x_pos, *y_pos))
	{
		++*x_pos;
		++*y_pos;
		return (true);
	}
	return (false);
}

bool				parse_room(char *str)
{
	char	*x_pos;
	char	*y_pos;
	char	*tmp;
	t_room	*room;

	if (!str)
		return (false);
	if (!set_coord_pos(str, &x_pos, &y_pos))
		return (false);
	room = malloc(sizeof(t_room));
	room->name = ft_strsub(str, 0, (x_pos - str - 1));
	tmp = ft_strsub(x_pos, 0, y_pos - x_pos - 1);
	room->x = ft_atoi(tmp);
	room->y = ft_atoi(y_pos);
	room->links = NULL;
	if (!ht_add(g_positions, ft_sformat("%d %d", room->x, room->y), 0))
		exit_error("room position duplicate");
	if (!ht_add(g_rooms, room->name, room))
		exit_error("room name duplicate");
	exec_cmd(room);
	free(tmp);
	return (true);
}
