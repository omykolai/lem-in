/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:33:39 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/06 15:39:16 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ht_funcs.h"

t_hashtable	*ht_new(void)
{
	return (ft_memalloc(sizeof(t_hashtable)));
}

void		ht_destroy(t_hashtable *ht, void (*del)(void *, size_t))
{
	t_list *keynode;

	keynode = ht->keys;
	while (keynode)
	{
		ft_lstdel(&ht->table[hashkey(keynode->value)], del);
		keynode = keynode->next;
	}
	ft_lstdel(&ht->keys, del_key);
	free(ht);
}
