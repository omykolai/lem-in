/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:27:45 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/07 17:06:33 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_room	t_room;
# define HASHVAL t_room *
# define TABLE_SIZE 65535

typedef struct	s_hashpair
{
	char		*key;
	HASHVAL		value;
}				t_hashpair;

typedef struct	s_hashtable
{
	t_list		*keys;
	t_list		*table[TABLE_SIZE];
}				t_hashtable;

t_hashtable		*ht_new();
void			ht_destroy(t_hashtable *ht, void (*del)(void *, size_t));

t_hashpair		*ht_get_pair(t_hashtable *ht, char *key);
bool			ht_add(t_hashtable *ht, char *key, HASHVAL value);
HASHVAL			ht_get(t_hashtable *ht, char *key);
bool			ht_remove(t_hashtable *ht, char *key,
	void (*del)(void *, size_t));

#endif
