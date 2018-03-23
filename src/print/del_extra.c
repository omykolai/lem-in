/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:23:20 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:20:18 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/print.h"
#include "../../ft_printf/includes/ft_printf.h"

static t_hashtable	*g_ht;

void			marker_room(t_list *n, t_path *p)
{
	t_roomnode	*node;

	node = n->value;
	if (node->room != g_farm.start)
		if (node->room != g_farm.end)
			if (!ht_add(g_ht, node->room->name, 0))
				ft_lstdelval(&g_farm.result.paths, p, NULL);
}

void			del_extra(t_list *paths)
{
	t_list	*n;

	g_ht = ht_new();
	while (paths)
	{
		n = ((t_path*)paths->value)->rooms->first;
		while (n)
		{
			marker_room(n, paths->value);
			n = n->next;
		}
		paths = paths->next;
	}
}
