/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:07:53 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/10 14:54:29 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_qpop(t_queue *q)
{
	void	*res;
	t_list	*newfirst;

	if (!q->first)
		return (NULL);
	res = q->first->value;
	newfirst = q->first->next;
	if (newfirst == NULL)
		q->last = NULL;
	free(q->first);
	q->first = newfirst;
	--q->count;
	return (res);
}
