/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:31:01 by omykolai          #+#    #+#             */
/*   Updated: 2017/12/26 15:52:59 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s_s1;
	const unsigned char	*s_s2;
	size_t				i;

	i = 0;
	s_s1 = s1;
	s_s2 = s2;
	if (!n)
		return (0);
	if (!s1 && !s2)
		return (0);
	while (*s_s1 == *s_s2 && ++i < n)
	{
		++s_s1;
		++s_s2;
	}
	return (*s_s1 - *s_s2);
}
