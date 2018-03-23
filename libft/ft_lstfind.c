/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:15:33 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/07 13:16:46 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *list, void *value)
{
	while (list)
	{
		if (list->value == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
