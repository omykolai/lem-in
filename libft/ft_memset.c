/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:36:58 by omykolai          #+#    #+#             */
/*   Updated: 2017/10/29 17:41:49 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c_u;
	unsigned char	*str;

	c_u = (unsigned char)c;
	str = b;
	while (len)
	{
		*str = c_u;
		++str;
		--len;
	}
	return (b);
}
