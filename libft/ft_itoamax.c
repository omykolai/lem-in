/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoamax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:00:36 by omykolai          #+#    #+#             */
/*   Updated: 2018/01/24 20:04:09 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static intmax_t	num_len(intmax_t n)
{
	intmax_t len;

	if (n < 0)
		len = 2;
	else
		len = 1;
	while (n > 9 || n < -9)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char			*ft_itoamax(intmax_t n)
{
	char		*res;
	intmax_t	len;

	len = num_len(n);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = 0;
	if (n < 0)
		res[0] = '-';
	while (n > 9 || n < -9)
	{
		if (n < 0)
			res[--len] = -(n % 10) + '0';
		else
			res[--len] = (n % 10) + '0';
		n /= 10;
	}
	res[--len] = (n < 0 ? -n : n) + '0';
	return (res);
}
