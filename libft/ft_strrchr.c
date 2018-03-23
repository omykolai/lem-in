/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:05:19 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/14 16:05:23 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char		cc;
	const char	*last_s;

	cc = (char)c;
	last_s = NULL;
	while (*s)
	{
		if (*s == cc)
			last_s = s;
		++s;
	}
	if (!c)
		return ((char*)s);
	return ((char*)last_s);
}
