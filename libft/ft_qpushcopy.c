/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpushcopy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:14:25 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/10 14:55:04 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qpushcopy(t_queue *q, void *val, size_t val_size)
{
	t_list	*new;

	new = NULL;
	ft_lstadd(&new, ft_lstnewcopy(val, val_size));
	if (q->last)
		q->last->next = new;
	q->last = new;
	if (!q->first)
		q->first = new;
	++q->count;
}
