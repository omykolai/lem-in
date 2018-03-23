/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:41:48 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:21:23 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include "lem_in.h"

struct s_inpath;

typedef struct	s_path
{
	t_queue			*rooms;
	struct s_inpath	*in_path;
	t_list			*co_paths;
	t_queue			*bfs_copaths;
	t_list			*finished;
	int				check;
}				t_path;

typedef struct	s_inpath
{
	t_path		*path;
	t_list		*end;
}				t_inpath;

typedef struct	s_roomnode
{
	t_room		*room;
	t_link		*inlink;
}				t_roomnode;

typedef struct	s_bfsnode
{
	t_room		*room;
	t_room		*prev_room;
	t_path		*path;
	int			search_level;
	bool		reached_first_branch;
	bool		discard;
	bool		skip;
}				t_bfsnode;

t_list			*g_finished;
t_list			*g_unfinished;
t_list			*g_pending_finish;
t_queue			*g_end_links;
int				*g_sums;
int				g_search_level;
int				g_ticks;

t_result		g_curres;
bool			g_copy;

t_bfsnode		*process_link(t_link *link, t_bfsnode *src);
void			process_path(t_link *link, t_bfsnode *node);
void			best_combination(t_path *path);

void			result_add(t_path *path);
void			set_check(t_path *path, int val);

void			finish_paths(t_list *paths);
void			finish_rooms(t_path *p);
void			finish_all_paths(t_queue *q, t_path *path);
void			finish_in_path(t_path *in_path, t_path *out_path);
void			add_in_paths(t_list *path_node, t_path *src);
void			add_finished(t_path *path, t_path *src);

void			bind_paths(t_path *p1, t_path *p2);
void			bind_with_copaths(t_path *p1, t_path *p2);
void			bind_finished(t_path *p1, t_path *p2);
bool			bind_room_paths(t_room *room, t_path *path);
void			bind_links_paths(t_path *path);
void			bind_all_paths(t_list *list, t_path *path);
bool			bind_list(t_queue *q, t_path *path);

bool			break_comb(int path_len, int max_count, bool append);
bool			break_bfs(void);

t_roomnode		*new_roomnode(t_room *room, t_link *link);
t_path			*new_path(t_room *room);
t_path			*dup_path(t_path *path, bool add_to_copaths, bool copy_all);
t_bfsnode		*new_node(t_room *room, t_path *path);
void			init_inpath(t_path *in_path, t_path *path);
void			copy_rooms(t_path *path, t_path *dup);
void			next_in_path(t_path **path, t_list **end);

#endif
