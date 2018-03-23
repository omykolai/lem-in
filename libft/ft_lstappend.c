/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:16:10 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:21:11 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstappend(t_list **alst, t_list *range)
{
	t_list	*l;

	if (!*alst)
		*alst = range;
	else
	{
		l = *alst;
		while (l->next)
			l = l->next;
		l->next = range;
	}
}
