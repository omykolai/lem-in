/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoamax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:01:47 by omykolai          #+#    #+#             */
/*   Updated: 2018/01/24 20:03:00 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static uintmax_t	num_len(uintmax_t n)
{
	uintmax_t len;

	len = 1;
	while (n > 9)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char				*ft_uitoamax(uintmax_t n)
{
	char		*res;
	uintmax_t	len;

	len = num_len(n);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = 0;
	while (n > 9)
	{
		res[--len] = (n % 10) + '0';
		n /= 10;
	}
	res[--len] = n + '0';
	return (res);
}
