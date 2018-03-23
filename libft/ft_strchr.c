/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:27:58 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/14 15:28:07 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char cc;

	cc = (char)c;
	while (*s && *s != cc)
		++s;
	if (*s == cc)
		return ((char*)s);
	return (NULL);
}
