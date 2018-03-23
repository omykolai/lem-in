/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_funcs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:42:09 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/06 15:37:38 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HT_FUNCS_H
# define HT_FUNCS_H
# include "hashtable.h"

int		hashkey(const char *key);
void	del_key(void *key, size_t size);

#endif
