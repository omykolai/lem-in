/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 10:39:13 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/05 18:04:00 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

typedef struct	s_buff
{
	char		value[BUFF_SIZE + 1];
	int			i;
}				t_buff;

int				get_next_line(int fd, char **line);

#endif
