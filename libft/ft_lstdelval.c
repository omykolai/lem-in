/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:47:07 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/10 17:14:26 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelval(t_list **list, void *val, void (*del)(void *, size_t))
{
	t_list *cur;
	t_list *tmp;

	cur = *list;
	if (cur->value == val)
	{
		*list = cur->next;
		ft_lstdelone(&cur, del);
	}
	else
	{
		while (cur->next)
		{
			if (cur->next->value == val)
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
