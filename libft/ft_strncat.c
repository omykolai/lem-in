/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 22:21:08 by omykolai          #+#    #+#             */
/*   Updated: 2017/09/25 22:21:46 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char *idst;

	idst = dst;
	while (*idst != '\0')
		++idst;
	while (*src != '\0' && n)
	{
		*idst = *src;
		++idst;
		++src;
		--n;
	}
	*idst = '\0';
	return (dst);
}
