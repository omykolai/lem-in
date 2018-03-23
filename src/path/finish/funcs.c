/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:49:57 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:36 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../includes/path.h"

static void			add_to_outpath(t_path *path, t_list *node)
{
	t_roomnode	*rn;

	while (node)
	{
		rn = node->value;
		ft_qpush_(rn->inlink->finished_paths, path);
		node = node->next;
	}
}

static void			add_bfscop(t_path *path, t_path *src)
{
	t_list	*cop;

	cop = ((t_queue*)src->bfs_copaths->first->value)->first;
	while (cop)
	{
		if (cop->value != src)
			bind_paths(cop->value, path);
		cop = cop->next;
	}
	path->bfs_copaths->first->value = src->bfs_copaths->first->value;
	ft_qpush_(path->bfs_copaths->first->value, path);
}

static void			add_inpath(t_path *path, t_list *node, t_path *src)
{
	t_path	*new;

	new = dup_path(path, true, true);
	ft_qaddrange(new->rooms, node);
	add_bfscop(new, src);
	add_finished(new, path);
	add_to_outpath(new, node);
	ft_lstadd_(&new->finished, new);
	best_combination(new);
}

void				add_in_paths(t_list *path_node, t_path *src)
{
	t_list	*in_paths;

	if (!((t_roomnode*)path_node->value)->inlink)
		return ;
	in_paths = ((t_roomnode*)path_node->value)->inlink->in_paths->first;
	while (in_paths)
	{
		add_inpath(in_paths->value, path_node, src);
		in_paths = in_paths->next;
	}
}

void				finish_in_path(t_path *in_path, t_path *out_path)
{
	t_list		*room;

	if (g_links > 10000)
		return ;
	room = out_path->rooms->first;
	while (room)
	{
		if (((t_roomnode*)room->value)->room ==
			((t_roomnode*)in_path->rooms->last->value)->room)
		{
			add_inpath(in_path, room->next, out_path);
			return ;
		}
		room = room->next;
	}
}
