/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:12:21 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/06 14:54:31 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ht_funcs.h"

t_hashpair	*ht_get_pair(t_hashtable *ht, char *key)
{
	t_list	*row;

	row = ht->table[hashkey(key)];
	while (row)
	{
		if (ft_strequ(((t_hashpair*)row->value)->key, key))
			return (row->value);
		row = row->next;
	}
	return (NULL);
}

bool		ht_add(t_hashtable *ht, char *key, HASHVAL value)
{
	t_hashpair	*p;

	if (!key || ht_get_pair(ht, key))
		return (false);
	p = malloc(sizeof(*p));
	p->key = key;
	p->value = value;
	ft_lstadd(&ht->table[hashkey(key)], ft_lstnew(p, 0));
	ft_lstadd(&ht->keys, ft_lstnew(ft_strdup(key), 0));
	return (true);
}

HASHVAL		ht_get(t_hashtable *ht, char *key)
{
	t_hashpair	*p;

	p = ht_get_pair(ht, key);
	if (p)
		return (p->value);
	return ((HASHVAL)NULL);
}

bool		ht_remove(t_hashtable *ht, char *key, void (*del)(void *, size_t))
{
	t_hashpair	*p;

	if (!key || !(p = ht_get_pair(ht, key)))
		return (false);
	ft_lstdelval(&ht->table[hashkey(key)], p, del);
	ft_lstdel_first_match(&ht->keys, key, del_key, ft_strcmp);
	return (true);
}
