/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:35:24 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/17 15:39:55 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *result;
	char *ires;

	if (!s || !(result = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ires = result;
	while (*s)
	{
		*ires = f(*s);
		++s;
		++ires;
	}
	*ires = '\0';
	return (result);
}
