/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:09:35 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/01 16:09:45 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*s_src;
	unsigned char		*s_dst;
	unsigned char		u_c;

	s_dst = (unsigned char*)dst;
	u_c = (unsigned char)c;
	s_src = (const unsigned char*)src;
	while (n)
	{
		*s_dst = *s_src;
		++s_dst;
		if (*s_src == u_c)
			return (s_dst);
		++s_src;
		--n;
	}
	return (NULL);
}
