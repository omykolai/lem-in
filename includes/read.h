/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:21:37 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:21:24 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include <stdbool.h>
# include "lem_in.h"

typedef enum	e_commands
{
	CMD_NONE,
	CMD_START,
	CMD_END,
}				t_commands;

typedef enum	e_rd_state
{
	RD_ROOMS,
	RD_LINKS,
}				t_rd_state;

typedef struct	s_rd_params
{
	t_commands	cmd;
	t_rd_state	state;
}				t_rd_params;

t_rd_params		g_rd_params;

bool			parse_room(char *str);
bool			parse_link(char *str);
bool			check_int(char *str, int len);

#endif
