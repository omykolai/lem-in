/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:11:22 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/10 14:54:53 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qpush(t_queue *q, void *val, size_t val_size)
{
	t_list	*new;

	new = NULL;
	ft_lstadd(&new, ft_lstnew(val, val_size));
	if (q->last)
		q->last->next = new;
	q->last = new;
	if (!q->first)
		q->first = new;
	++q->count;
}
