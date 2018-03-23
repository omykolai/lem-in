/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:14:59 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/01 18:15:04 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ss;
	unsigned char			cc;

	ss = (const unsigned char*)s;
	cc = (unsigned char)c;
	while (n)
	{
		if (*ss == cc)
			return ((void*)ss);
		++ss;
		--n;
	}
	return (NULL);
}
