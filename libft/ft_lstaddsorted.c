/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddsorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:42:28 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/10 14:51:11 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddsorted(t_list **alst, void *val, int (*cmp)())
{
	t_list	*node;
	t_list	*new;

	if (!*alst || cmp((*alst)->value, val) >= 0)
		ft_lstadd_(alst, val);
	else
	{
		node = *alst;
		while (node->next && cmp(node->next->value, val) < 0)
			node = node->next;
		new = ft_lstnew(val, 0);
		new->next = node->next;
		node->next = new;
	}
}
