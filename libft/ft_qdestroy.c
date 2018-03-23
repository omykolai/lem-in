/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qdestroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:23:49 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/07 16:26:20 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_qdestroy(t_queue *q, void (*del)(void *, size_t))
{
	ft_lstdel(&q->first, del);
	free(q);
}
