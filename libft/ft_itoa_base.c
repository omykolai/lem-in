/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:20:25 by omykolai          #+#    #+#             */
/*   Updated: 2018/01/25 14:57:14 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	num_len(uintmax_t n, size_t blen)
{
	size_t len;

	len = 1;
	while (n > (blen - 1))
	{
		++len;
		n /= blen;
	}
	return (len);
}

char			*ft_itoa_base(uintmax_t n, char *base)
{
	char	*res;
	size_t	len;
	size_t	blen;

	blen = ft_strlen(base);
	len = num_len(n, blen);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = 0;
	while (n > (blen - 1))
	{
		res[--len] = base[n % blen];
		n /= blen;
	}
	res[--len] = base[n];
	return (res);
}
