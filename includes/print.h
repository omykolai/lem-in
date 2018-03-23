/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:45:32 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:21:23 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include "path.h"

typedef struct	s_move
{
	t_list		*move;
	int			ant;
}				t_move;

typedef struct	s_moves
{
	t_list		*p;
	t_move		*m;
	int			m_count;
	int			count;
}				t_moves;

int				get_sumlen(void);
void			set_all_moves(t_moves *moves, int path_count, int sum_len);
void			del_extra(t_list *paths);
void			moves_del(t_moves *m, int n);

#endif
