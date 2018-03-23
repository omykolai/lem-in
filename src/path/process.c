/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:09:57 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:41 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/path.h"

void				process_path(t_link *link, t_bfsnode *node)
{
	ft_qpush_(node->path->rooms, new_roomnode(link->next_room, link));
	ft_qpush_(link->out_paths, node->path);
	node->prev_room = node->room;
	node->room = link->next_room;
}

static t_bfsnode	*get_node_copy(t_bfsnode *src, t_link *link)
{
	t_bfsnode			*new;

	if (!g_copy)
	{
		g_copy = true;
		g_search_level = ++src->search_level;
		return (src);
	}
	else
	{
		new = new_node(src->room,
		dup_path(src->path, src->search_level > 1, src->search_level <= 1));
		ft_lstadd_(&g_unfinished, new);
		new->search_level = src->search_level;
		new->skip = src->skip;
		bind_links_paths(new->path);
		process_path(link, new);
		if (src->search_level > 1)
		{
			new->reached_first_branch = true;
			src->reached_first_branch = true;
		}
		return (new);
	}
}

void				set_headed_to_start(t_room *room, t_room *prev_room)
{
	t_list	*links;
	t_link	*l;

	links = room->links;
	while (links)
	{
		l = links->value;
		if (l->next_room == prev_room)
			l->headed_to_start = true;
		links = links->next;
	}
}

static bool			check_link(t_link *link, t_bfsnode *src)
{
	if (!src->reached_first_branch)
		set_headed_to_start(link->next_room, src->room);
	if (link->next_room == src->prev_room || link->headed_to_start)
		return (false);
	return (true);
}

t_bfsnode			*process_link(t_link *link, t_bfsnode *src)
{
	if (!check_link(link, src))
		return (NULL);
	if (link->out_paths->first)
	{
		if (src->skip || bind_room_paths(src->room, src->path))
		{
			finish_all_paths(link->out_paths, src->path);
			ft_qpush_(link->in_paths, src->path);
		}
		src->skip = true;
	}
	else
		src = get_node_copy(src, link);
	if (src && link->next_room == g_farm.end)
	{
		src->discard = true;
		ft_lstadd_(&g_pending_finish, src->path);
		if (!ft_lstfind(g_end_links->first, link))
			ft_qpush_(g_end_links, link);
	}
	return (src);
}
