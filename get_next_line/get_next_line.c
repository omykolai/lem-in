/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 10:38:37 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/05 17:43:47 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "get_next_line.h"

static char		*join_pieces(t_queue *l, int len)
{
	char	*line;
	t_list	*piece;
	int		offset;

	if (!l->first)
		return (NULL);
	if (!(line = ft_strnew(sizeof(*line) * (len))))
		return (NULL);
	offset = 0;
	while ((piece = ft_qpopnode(l)))
	{
		ft_strncpy(line + offset, piece->value, piece->value_size);
		offset += piece->value_size;
		free(piece->value);
		free(piece);
	}
	return (line);
}

static t_buff	*set_line(t_buff *b, t_queue *l, int *line_len)
{
	char	*s;
	char	*end;
	int		len;

	s = b->value + b->i;
	end = ft_strchr(s, '\n');
	if (end)
	{
		len = end - s;
		b->i += len + 1;
		ft_qpush(l, ft_strsub(s, 0, len), len);
	}
	else
	{
		if (*s)
			ft_qpush(l, ft_strdup(s), ft_strlen(s));
		ft_bzero(b, sizeof(*b));
	}
	*line_len += l->last ? l->last->value_size : 0;
	return (end ? NULL : b);
}

static int		read_fd(int fd, t_buff *b, t_queue *l, int *len)
{
	int		red;

	if (!b)
		return (1);
	while ((red = read(fd, b->value, BUFF_SIZE)) > 0)
	{
		b->value[red] = 0;
		if (!set_line(b, l, len))
			return (1);
	}
	return (red < 0 ? -1 : red || *len);
}

static t_buff	*read_buff(int fd, t_list **buffs, t_queue *line, int *len)
{
	t_list	*cur;

	cur = *buffs;
	while (cur)
	{
		if ((int)cur->value_size == fd)
			return (set_line(cur->value, line, len));
		cur = cur->next;
	}
	ft_lstadd(buffs, ft_lstnew(ft_memalloc(sizeof(t_buff)), fd));
	return ((*buffs)->value);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*buffs = NULL;
	t_buff			*buff;
	t_queue			*line_pieces;
	int				len;
	int				result;

	if (fd < 0 || !line)
		return (-1);
	len = 0;
	line_pieces = ft_qnew();
	buff = read_buff(fd, &buffs, line_pieces, &len);
	result = read_fd(fd, buff, line_pieces, &len);
	*line = join_pieces(line_pieces, len);
	if (!*line && result == 1)
		result = -1;
	free(line_pieces);
	return (result);
}
