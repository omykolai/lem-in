/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:23:20 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:39 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/path.h"

void		bind_finished(t_path *p1, t_path *p2)
{
	t_list	*plist;
	t_list	*cop;

	plist = p1->bfs_copaths->first;
	while (plist)
	{
		cop = ((t_queue*)plist->value)->first;
		while (cop)
		{
			if (((t_path*)cop->value)->finished)
				bind_all_paths(((t_path*)cop->value)->finished, p2);
			cop = cop->next;
		}
		plist = plist->next;
	}
	set_check(p2, -1);
}

void		bind_with_copaths(t_path *p1, t_path *p2)
{
	t_queue	*cop;
	t_list	*c;

	cop = p1->bfs_copaths->first->value;
	ft_qpush_(cop, p2);
	p2->bfs_copaths->first->value = cop;
	c = p1->bfs_copaths->first->next;
	while (c)
	{
		ft_qpush_(p2->bfs_copaths, c->value);
		c = c->next;
	}
}

bool		bind_room_paths(t_room *room, t_path *path)
{
	t_list	*links;
	t_link	*l;

	links = room->links;
	while (links)
	{
		l = links->value;
		bind_list(l->in_paths, path);
		bind_list(l->finished_paths, path);
		if (!bind_list(l->out_paths, path))
			return (false);
		links = links->next;
	}
	return (true);
}

void		bind_links_paths(t_path *path)
{
	t_list		*rooms;
	t_list		*end;
	t_path		*p;
	t_roomnode	*n;

	end = NULL;
	p = path;
	while (p)
	{
		rooms = p->rooms->first;
		while (rooms != end)
		{
			n = rooms->value;
			if (n->inlink)
				ft_qpush_(n->inlink->out_paths, path);
			rooms = rooms->next;
		}
		next_in_path(&p, &end);
	}
}
