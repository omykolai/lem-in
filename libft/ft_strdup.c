/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:05:40 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/11 15:19:48 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*idup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	idup = dup;
	while (*s1)
	{
		*idup = *s1;
		++idup;
		++s1;
	}
	*idup = '\0';
	return (dup);
}
