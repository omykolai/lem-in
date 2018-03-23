/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:49:36 by omykolai          #+#    #+#             */
/*   Updated: 2017/10/29 19:01:54 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s_src;
	unsigned char		*s_dst;

	s_dst = dst;
	s_src = src;
	while (n)
	{
		*s_dst = *s_src;
		++s_dst;
		++s_src;
		--n;
	}
	return (dst);
}
