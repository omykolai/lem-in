/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpopnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:08:59 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/10 14:54:41 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_qpopnode(t_queue *q)
{
	t_list	*res;
	t_list	*newfirst;

	if (!q->first)
		return (NULL);
	res = q->first;
	newfirst = q->first->next;
	if (newfirst == NULL)
		q->last = NULL;
	q->first = newfirst;
	--q->count;
	return (res);
}
