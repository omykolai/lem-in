/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_first_match.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:09:00 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/10 17:17:09 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_first_match(t_list **list, void *val,
	void (*del)(void *, size_t), int (*cmp)())
{
	t_list *cur;
	t_list *tmp;

	cur = *list;
	if (cmp(cur->value, val) == 0)
	{
		*list = cur->next;
		ft_lstdelone(&cur, del);
	}
	else
	{
		while (cur->next)
		{
			if (cmp(cur->next->value, val) == 0)
			{
				tmp = cur->next->next;
				ft_lstdelone(&cur->next, del);
				cur->next = tmp;
				return ;
			}
			cur = cur->next;
		}
	}
}
