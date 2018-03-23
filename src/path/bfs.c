/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:07:29 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 13:53:25 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/path.h"

static const int	g_max_iters = 1000000;

static inline void	init_bfs(t_queue **bfs_q, t_bfsnode **n)
{
	*bfs_q = ft_qnew();
	*n = new_node(g_farm.start, new_path(g_farm.start));
	g_finished = NULL;
	g_unfinished = NULL;
	g_end_links = ft_qnew();
	g_search_level = 0;
	g_ticks = 0;
	g_sums = ft_memalloc(sizeof(*g_sums) * g_farm.max_path_count);
}

static inline void	init_bfs_next(t_list **l, t_link **link, bool *b,
									t_bfsnode *src)
{
	*l = src->room->links;
	g_copy = false;
	*link = NULL;
	*b = false;
	g_pending_finish = NULL;
}

static inline void	process_rest(t_link *src_link, t_bfsnode *src, bool proc)
{
	if (proc)
	{
		process_path(src_link, src);
		finish_paths(g_pending_finish);
	}
	ft_lstdel(&g_pending_finish, NULL);
}

static bool			bfs_next(t_queue *bfs_q, t_bfsnode *src)
{
	t_list		*l;
	t_link		*src_link;
	t_bfsnode	*next;
	bool		has_next;
	bool		res;

	init_bfs_next(&l, &src_link, &has_next, src);
	res = false;
	while (l)
	{
		next = process_link(l->value, src);
		if (next && !next->skip)
		{
			if (!next->discard)
			{
				ft_qpush_(bfs_q, next);
				res = true;
			}
			src_link = next == src ? l->value : src_link;
			has_next = true;
		}
		l = l->next;
	}
	process_rest(src_link, src, has_next);
	return (res);
}

bool				find_paths(void)
{
	t_queue		*bfs_q;
	t_bfsnode	*n;

	init_bfs(&bfs_q, &n);
	bfs_next(bfs_q, n);
	ft_lstadd_(&g_unfinished, n);
	while ((n = ft_qpop(bfs_q)) &&
		(g_ticks < g_max_iters || !g_farm.result.paths))
	{
		++g_ticks;
		if (!bfs_next(bfs_q, n))
			ft_memdel((void**)&n);
		if (break_bfs())
			break ;
	}
	free(n);
	ft_qdestroy(bfs_q, NULL);
	return (g_farm.result.paths != NULL);
}
