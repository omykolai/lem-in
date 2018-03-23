/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:16:45 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:35 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../includes/path.h"

void		init_inpath(t_path *in_path, t_path *path)
{
	t_inpath	*inp;

	inp = malloc(sizeof(*inp));
	inp->path = in_path;
	inp->end = in_path->rooms->last;
	path->rooms = ft_qnew();
	ft_qpush_(path->rooms, inp->end->value);
	path->in_path = inp;
}

void		copy_rooms(t_path *path, t_path *dup)
{
	t_list	*end;
	t_queue	*res;
	t_queue	*rooms;

	end = NULL;
	res = ft_qnew();
	while (path)
	{
		rooms = ft_qsub(path->rooms, end);
		ft_qaddrange(rooms, res->first);
		free(res);
		res = rooms;
		next_in_path(&path, &end);
	}
	dup->rooms = res;
}

void		next_in_path(t_path **path, t_list **end)
{
	if ((*path)->in_path)
	{
		*end = (*path)->in_path->end;
		*path = (*path)->in_path->path;
	}
	else
		*path = NULL;
}
