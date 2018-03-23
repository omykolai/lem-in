/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:08:26 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/07 18:28:32 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *list)
{
	t_list	*copy;
	t_list	**next;

	if (!list)
		return (NULL);
	copy = ft_lstnew(list->value, list->value_size);
	next = &copy->next;
	while (list->next)
	{
		*next = ft_lstnew(list->next->value, list->next->value_size);
		list = list->next;
		next = &(*next)->next;
	}
	return (copy);
}
