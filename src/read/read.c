/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:32:09 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 13:27:04 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../../includes/read.h"
#include "../../get_next_line/get_next_line.h"
#define MIN(a, b) ((a) < (b) ? a : b)

static void	init_read(t_queue **q)
{
	*q = ft_qnew();
	g_farm.start = NULL;
	g_farm.end = NULL;
	g_farm.result.paths = NULL;
	g_farm.result.steps = INT_MAX;
	g_rd_params.cmd = CMD_NONE;
	g_rd_params.state = RD_ROOMS;
	g_rooms = ht_new();
	g_positions = ht_new();
	g_links = 0;
}

static void	read_comment(char *line)
{
	if (g_rd_params.cmd != CMD_NONE)
		exit_error("command execute error");
	++line;
	if (*line == '#')
	{
		++line;
		if (ft_strequ(line, "start"))
			g_rd_params.cmd = CMD_START;
		else if (ft_strequ(line, "end"))
			g_rd_params.cmd = CMD_END;
	}
}

static void	read_farm_item(char *line)
{
	if (g_rd_params.state == RD_ROOMS)
	{
		if (!parse_room(line))
		{
			if (!parse_link(line))
				exit_error("read room error");
			if (!g_farm.start)
				exit_error("start room not found");
			if (!g_farm.end)
				exit_error("end room not found");
			g_rd_params.state = RD_LINKS;
		}
	}
	else if (g_rd_params.state == RD_LINKS)
		if (!parse_link(line))
			exit_error("ERROR");
	g_rd_params.cmd = CMD_NONE;
}

static char	*read_ant_num(int fd, t_queue *input)
{
	char	*line;
	int		res;

	while ((res = get_next_line(fd, &line) > 0))
	{
		ft_qpush_(input, line);
		if (*line != '#')
		{
			if (res == 0 || !check_int(line, ft_strlen(line)))
				exit_error("wrong ant count");
			if (g_error_color)
				g_farm.ant_count = ft_atoi(line);
			if (g_farm.ant_count <= 0)
				exit_error("ant should be more than zero");
			return (line);
		}
		else
			read_comment(line);
		if (g_rd_params.cmd != CMD_NONE)
			exit_error("command execute error");
	}
	if (res < 0)
		exit_error("file read error");
	return (line);
}

t_queue		*read_farm(int fd)
{
	t_queue	*input;
	char	*line;
	int		res;

	init_read(&input);
	read_ant_num(fd, input);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		ft_qpush_(input, line);
		if (*line == '#')
			read_comment(line);
		else if (*line && *line != 'L')
			read_farm_item(line);
		else
			exit_error("wrong line format");
	}
	if (res < 0)
		exit_error("read error");
	if (g_rd_params.cmd != CMD_NONE || !g_farm.start || !g_farm.end)
		exit_error("ERROR");
	g_farm.max_path_count =
		MIN(ft_lstlen(g_farm.start->links), ft_lstlen(g_farm.end->links));
	return (input);
}
