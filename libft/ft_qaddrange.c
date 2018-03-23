/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qaddrange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:37:11 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:21:00 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qaddrange(t_queue *q, t_list *range)
{
	q->last->next = range;
	while (range)
	{
		++q->count;
		q->last = range;
		range = range->next;
	}
}
