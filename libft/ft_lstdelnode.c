/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:33:42 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/10 17:14:36 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnode(t_list **list, t_list *node, void (*del)(void *, size_t))
{
	t_list *cur;

	cur = *list;
	if (cur == node)
	{
		*list = cur->next;
		ft_lstdelone(&cur, del);
	}
	else
	{
		while (cur->next)
		{
			if (cur->next == node)
			{
				cur->next = cur->next->next;
				ft_lstdelone(&node, del);
				return ;
			}
			cur = cur->next;
		}
	}
}
