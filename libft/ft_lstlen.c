/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:01:01 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/10 14:01:59 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *list)
{
	int	len;

	len = 0;
	while (list)
	{
		++len;
		list = list->next;
	}
	return (len);
}
