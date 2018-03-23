/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:26:57 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/10 16:29:21 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void *value, size_t value_size)
{
	t_list	*first;

	if (!(first = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	first->value = value;
	first->value_size = value == NULL ? 0 : value_size;
	first->next = NULL;
	return (first);
}
