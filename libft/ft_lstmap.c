/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:49:41 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/18 14:49:44 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*curr;

	if (!lst || !(first = f(lst)))
		return (NULL);
	curr = first;
	lst = lst->next;
	while (lst)
	{
		if (!(curr->next = f(lst)))
			return (NULL);
		lst = lst->next;
		curr = curr->next;
	}
	return (first);
}
