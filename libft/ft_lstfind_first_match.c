/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_first_match.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:16:58 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/07 13:18:23 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_first_match(t_list *list, void *value, int (*cmp)())
{
	while (list)
	{
		if (cmp(list->value, value) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}
