/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:23:20 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:38 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/path.h"

void		bind_paths(t_path *p1, t_path *p2)
{
	ft_lstadd_(&p1->co_paths, p2);
	ft_lstadd_(&p2->co_paths, p1);
}

void		bind_all_paths(t_list *list, t_path *path)
{
	t_path	*p;

	while (list)
	{
		p = list->value;
		if (p->check == 0 && p != path)
			bind_paths(p, path);
		p->check = 1;
		list = list->next;
	}
}

static void	add_cop(t_list *l, t_path *path, bool *res)
{
	t_queue	*cop;

	if (l->value != path)
	{
		cop = ft_qnew();
		ft_qpush_(cop, path);
		ft_qpush_(((t_path*)l->value)->bfs_copaths, cop);
	}
	else
		*res = false;
}

bool		bind_list(t_queue *q, t_path *path)
{
	t_list	*l;
	bool	res;

	res = true;
	l = q->first;
	if (l)
		ft_qpush_(path->bfs_copaths, q);
	while (l)
	{
		add_cop(l, path, &res);
		l = l->next;
	}
	return (res);
}
