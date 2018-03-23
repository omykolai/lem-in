/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:49:57 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:37 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/path.h"

static int		cmp_paths(t_path *p1, t_path *p2)
{
	return (p1->rooms->count - p2->rooms->count);
}

void			add_finished(t_path *path, t_path *src)
{
	ft_lstaddsorted(&g_finished, path, cmp_paths);
	ft_lstadd_(&src->finished, path);
}

void			finish_all_paths(t_queue *q, t_path *path)
{
	t_list	*l;
	t_list	*out_paths;

	l = q->first;
	while (l)
	{
		if (((t_path*)l->value)->finished)
		{
			out_paths = ((t_path*)l->value)->finished;
			while (out_paths)
			{
				finish_in_path(path, out_paths->value);
				out_paths = out_paths->next;
			}
		}
		l = l->next;
	}
}

void			finish_rooms(t_path *p)
{
	t_list	*room;

	if (g_links > 10000)
		return ;
	room = p->rooms->first;
	while (room)
	{
		add_in_paths(room, p);
		room = room->next;
	}
}

void			finish_paths(t_list *paths)
{
	t_path	*p;

	while (paths)
	{
		if (((t_roomnode*)((t_path*)paths->value)->rooms->last->value)->room
			== g_farm.end)
		{
			p = dup_path(paths->value, true, true);
			add_finished(p, paths->value);
			best_combination(p);
			finish_rooms(p);
		}
		paths = paths->next;
	}
}
