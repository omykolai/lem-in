/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:00:12 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:44 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/print.h"
#include "../../ft_printf/includes/ft_printf.h"

static int		g_ant;

static char		*append_mline(char *res, t_move *m)
{
	char	*tmp;
	char	*room_name;

	if (m->move)
	{
		room_name = ((t_roomnode*)m->move->value)->room->name;
		if (res)
		{
			tmp = res;
			res = ft_sformat("%s L%d-%s", res, m->ant, room_name);
			free(tmp);
		}
		else
			res = ft_sformat("L%d-%s", m->ant, room_name);
		m->move = m->move->next;
	}
	return (res);
}

static char		*join_lines(char *l1, char *l2)
{
	char	*res;

	if (l1 && l2)
	{
		res = ft_sformat("%s %s", l1, l2);
		free(l1);
		free(l2);
	}
	else if (l1)
		res = l1;
	else if (l2)
		res = l2;
	else
		res = NULL;
	return (res);
}

static void		append_move_line(t_moves *m, char **line)
{
	char	*res;
	int		i;

	i = -1;
	res = NULL;
	while (++i < m->m_count)
		res = append_mline(res, &m->m[i]);
	if (m->m_count < m->count)
	{
		m->m[m->m_count].move = m->p;
		m->m[m->m_count].ant = ++g_ant;
		res = append_mline(res, &m->m[m->m_count]);
		++m->m_count;
	}
	*line = join_lines(*line, res);
}

static char		*get_moves_line(t_moves *m, int path_count)
{
	int		i;
	char	*line;

	i = -1;
	line = NULL;
	while (++i < path_count)
		append_move_line(&m[i], &line);
	return (line);
}

void			print_path(void)
{
	t_moves	*moves;
	int		path_count;
	int		sum_len;
	char	*line;

	del_extra(g_farm.result.paths);
	path_count = ft_lstlen(g_farm.result.paths);
	sum_len = get_sumlen();
	moves = malloc(sizeof(*moves) * path_count);
	g_ant = 0;
	set_all_moves(moves, path_count, sum_len);
	while ((line = get_moves_line(moves, path_count)))
	{
		ft_printf("%s\n", line);
		free(line);
	}
	moves_del(moves, path_count);
}
