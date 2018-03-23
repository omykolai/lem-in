/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:03:54 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/01 17:03:58 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s_src;
	unsigned char		*s_dst;
	int					add_diff;

	s_dst = dst;
	s_src = src;
	add_diff = s_dst - s_src;
	if (add_diff > 0 && (size_t)add_diff < len)
	{
		while (len--)
			s_dst[len] = s_src[len];
	}
	else
	{
		while (len)
		{
			*s_dst = *s_src;
			++s_dst;
			++s_src;
			--len;
		}
	}
	return (dst);
}
