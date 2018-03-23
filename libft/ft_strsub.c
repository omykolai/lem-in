/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:12:46 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/17 16:17:05 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s || !(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		sub[i] = s[start];
		++start;
	}
	sub[i] = 0;
	return (sub);
}
