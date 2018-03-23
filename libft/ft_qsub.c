/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:45:02 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/12 16:50:45 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_queue	*ft_qsub(t_queue *q, t_list *end)
{
	t_queue	*res;
	t_list	*list;
	t_list	**next;

	if (!q)
		return (NULL);
	res = ft_qnew();
	list = q->first;
	if (!list || list == end)
		return (res);
	res->first = ft_lstnew(list->value, list->value_size);
	res->last = res->first;
	next = &res->first->next;
	++res->count;
	while (list->next != end)
	{
		*next = ft_lstnew(list->next->value, list->next->value_size);
		res->last = *next;
		list = list->next;
		next = &(*next)->next;
		++res->count;
	}
	return (res);
}
