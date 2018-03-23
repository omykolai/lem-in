/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:17:12 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/10 18:28:11 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_queue	*ft_qdup(t_queue *q)
{
	t_queue	*res;
	t_list	*list;
	t_list	**next;

	if (!q)
		return (NULL);
	res = ft_qnew();
	list = q->first;
	if (!list)
		return (res);
	res->first = ft_lstnew(list->value, list->value_size);
	res->last = res->first;
	next = &res->first->next;
	while (list->next)
	{
		*next = ft_lstnew(list->next->value, list->next->value_size);
		res->last = *next;
		list = list->next;
		next = &(*next)->next;
	}
	res->count = q->count;
	return (res);
}
