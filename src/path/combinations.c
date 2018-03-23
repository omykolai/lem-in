/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:23:20 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:42 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/path.h"

static int			g_iterations;
static const int	g_max_iters = 10000;

void		set_check(t_path *path, int val)
{
	t_list	*co_paths;
	t_path	*p;

	path->check += val;
	co_paths = path->co_paths;
	while (co_paths)
	{
		p = co_paths->value;
		p->check += val;
		co_paths = co_paths->next;
	}
}

static void	increment_iter(void)
{
	++g_ticks;
	++g_iterations;
}

static void	next_combination(t_path *path, int level)
{
	t_list	*f;
	t_path	*p;

	increment_iter();
	if (g_iterations < g_max_iters &&
		!break_comb(path->rooms->count - 1, g_end_links->count, false))
	{
		result_add(path);
		if (--level)
		{
			set_check(path, 1);
			f = g_finished;
			while (f)
			{
				p = f->value;
				if (p->check == 0)
					next_combination(p, level);
				f = f->next;
			}
			set_check(path, -1);
		}
		else
			g_iterations = g_max_iters;
		ft_lstdelval(&g_curres.paths, path, NULL);
	}
}

void		best_combination(t_path *path)
{
	g_curres.paths = NULL;
	g_iterations = 0;
	next_combination(path, g_end_links->count);
}
