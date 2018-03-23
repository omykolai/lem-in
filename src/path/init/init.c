/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:22:34 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:27 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../includes/path.h"

t_roomnode	*new_roomnode(t_room *room, t_link *link)
{
	t_roomnode	*n;

	n = malloc(sizeof(*n));
	n->room = room;
	n->inlink = link;
	return (n);
}

t_path		*new_path(t_room *room)
{
	t_path	*p;
	t_queue	*q;

	p = ft_memalloc(sizeof(*p));
	p->rooms = ft_qnew();
	p->bfs_copaths = ft_qnew();
	q = ft_qnew();
	ft_qpush_(q, p);
	ft_qpush_(p->bfs_copaths, q);
	ft_qpush_(p->rooms, new_roomnode(room, NULL));
	p->check = 0;
	return (p);
}

t_path		*dup_path(t_path *path, bool add_to_copaths, bool copy_all)
{
	t_path	*p;
	t_queue	*q;

	p = ft_memalloc(sizeof(*p));
	p->bfs_copaths = ft_qnew();
	q = ft_qnew();
	ft_lstadd_(&g_unfinished, q);
	ft_qpush_(q, p);
	ft_qpush_(p->bfs_copaths, q);
	if (copy_all)
		copy_rooms(path, p);
	else
		init_inpath(path, p);
	if (add_to_copaths)
	{
		if (copy_all)
			bind_finished(path, p);
		else
			bind_with_copaths(path, p);
	}
	p->check = path->check;
	return (p);
}

t_bfsnode	*new_node(t_room *room, t_path *path)
{
	t_bfsnode	*n;

	n = ft_memalloc(sizeof(t_bfsnode));
	n->room = room;
	n->path = path;
	return (n);
}
