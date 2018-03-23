/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewcopy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:49:54 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/10 16:26:26 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*get_copy(unsigned char *c, size_t size)
{
	unsigned char	*c_copy;

	if (!(c_copy = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	while (--size)
		c_copy[size] = c[size];
	*c_copy = *c;
	return ((void*)c_copy);
}

t_list		*ft_lstnewcopy(void const *value, size_t value_size)
{
	t_list	*first;

	if (!(first = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!value)
	{
		first->value = NULL;
		first->value_size = 0;
	}
	else
	{
		if (!(first->value = get_copy((unsigned char*)value, value_size)))
			return (NULL);
		first->value_size = value_size;
	}
	first->next = NULL;
	return (first);
}
