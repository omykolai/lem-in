/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:23:20 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:46 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/read.h"

static inline t_link	*new_link(t_room *room)
{
	t_link	*l;

	l = malloc(sizeof(*l));
	l->next_room = room;
	l->in_paths = ft_qnew();
	l->out_paths = ft_qnew();
	l->finished_paths = ft_qnew();
	l->headed_to_start = false;
	return (l);
}

static void				link_rooms(t_room *r1, t_room *r2)
{
	ft_lstadd_(&r1->links, new_link(r2));
	ft_lstadd_(&r2->links, new_link(r1));
}

static bool				try_add_link(char *key1, char *key2)
{
	t_room	*room1;
	t_room	*room2;

	if ((room1 = ht_get(g_rooms, key1)) &&
		(room2 = ht_get(g_rooms, key2)))
	{
		if (room1 != room2)
		{
			++g_links;
			link_rooms(room1, room2);
			free(key1);
		}
		return (true);
	}
	free(key1);
	return (false);
}

bool					parse_link(char *str)
{
	char	*istr;
	bool	res;

	if (g_rd_params.cmd != CMD_NONE)
		exit_error("command execute error");
	istr = str;
	res = false;
	while (*istr)
	{
		if (*istr == '-')
			if (try_add_link(ft_strsub(str, 0, istr - str), istr + 1))
			{
				if (res)
					exit_error("ambiguous link");
				res = true;
			}
		++istr;
	}
	return (res);
}
