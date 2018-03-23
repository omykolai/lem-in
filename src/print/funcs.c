/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:00:12 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:44 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/print.h"

static int		g_ants_used;

int				get_sumlen(void)
{
	int		len;
	t_list	*paths;

	len = 0;
	paths = g_farm.result.paths;
	while (paths)
	{
		len += ((t_path*)paths->value)->rooms->count - 1;
		paths = paths->next;
	}
	return (len);
}

static t_moves	get_moves(t_path *p, int path_count, int sum_len)
{
	t_moves	res;

	res.p = p->rooms->first->next;
	res.count = sum_len - path_count * (p->rooms->count - 1) + g_farm.ant_count;
	res.count = ft_divceil(res.count, path_count);
	g_ants_used += res.count;
	if (g_ants_used > g_farm.ant_count)
	{
		res.count -= g_ants_used - g_farm.ant_count;
		g_ants_used = g_farm.ant_count;
	}
	res.m = ft_memalloc(sizeof(*res.m) * res.count);
	res.m_count = 0;
	return (res);
}

void			set_all_moves(t_moves *moves, int path_count, int sum_len)
{
	t_list	*paths;
	int		i;

	paths = g_farm.result.paths;
	g_ants_used = 0;
	i = -1;
	while (paths)
	{
		moves[++i] = get_moves(paths->value, path_count, sum_len);
		paths = paths->next;
	}
}

void			moves_del(t_moves *m, int n)
{
	while (n--)
		free(m[n].m);
	free(m);
}
