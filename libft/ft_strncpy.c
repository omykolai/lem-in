/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:06:20 by omykolai          #+#    #+#             */
/*   Updated: 2017/09/25 14:23:24 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *idst;

	idst = dst;
	while (len && *src != '\0')
	{
		*idst = *src;
		++idst;
		++src;
		--len;
	}
	while (len)
	{
		*idst = '\0';
		++idst;
		--len;
	}
	return (dst);
}
