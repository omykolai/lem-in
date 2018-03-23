/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:15:25 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/17 21:16:10 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	num_len(int n)
{
	int len;

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

char		*ft_itoa(int n)
{
	char	*res;
	int		len;

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
